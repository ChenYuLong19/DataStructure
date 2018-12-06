#include"AdjListUndirGraph.h"
using namespace std;
template<class ET, class WT>
AdjListUndirGraph<ET, WT>::AdjListUndirGraph(ET es[], int vertexNum, int vertexMaxNum, WT infinit)
{
	if (vertexMaxNum < 0)
		throw Error("允许的顶点的最大的数目不能小于0！");
	if (vertexNum > vertexMaxNum)
		throw Error("顶点的数目不能大于顶点允许的最大数目！");
	vexNum = vertexNum;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;
	infinity = infinit;
	tag = new int[vertexMaxNum];
	vexTable = new AdjListUndirGraphVex<ET, WT>[vertexMaxNum];
	for (int v = 0; v < vertexNum; v++)
	{
		tag[v] = 0; //默认顶点没有被访问
		vexTable[v].data = es[v];
		vexTable[v].firstarc = NULL;
	}
}
template<class ET, class WT>
AdjListUndirGraph<ET, WT>::AdjListUndirGraph(int vertexMaxNum, WT infinit)
{
	if (vertexMaxNum < 0)
		throw Error("允许的顶点的最大数目不能小于0！");
	vexNum = 0;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;
	infinity = infinit;
	tag = new int[vertexMaxNum];
	vexTable = new AdjListUndirGraphVex<ET, WT>[vertexMaxNum];
}

template<class ET, class WT>
AdjListUndirGraph<ET, WT>::~AdjListUndirGraph()
{
	Clear();
}

template<class ET, class WT>
void AdjListUndirGraph<ET, WT>::Clear()
{
	delete[]vexTable;
}

template<class ET, class WT>
string AdjListUndirGraph<ET, WT>::Error(string str)
{
	return str;
}

template<class ET, class WT>
void AdjListUndirGraph<ET, WT>::DFS(int v)
{
	tag[v - 1] = 1;  //设置v的访问标志为已访问1
	cout << vexTable[v - 1].data << " "; //访问顶点v
	for (int w = FirstAdjVex(v); w != -1; w = NextAdgVex(v, w))
		if (tag[w - 1] == 0)
			DFS(w);  //递归找该顶点的下一条边
}

template<class ET, class WT>
void AdjListUndirGraph<ET, WT>::DFSTraverse()
{
	for (int v = 0; v < vexNum; v++)
		tag[v] = 0;  /*这个v是数组从0开始的，其他的因为是顶点的编号进数组要减1*/
	for (int v = 0; v < vexNum; v++)
		if (tag[v] == 0)  //没有访问
			DFS(v + 1);  /*从0开始的编号静进入顶点编号要加1*/
}


template<class ET, class WT>
void AdjListUndirGraph<ET, WT>::SetTag(int v, int t)
{
	tag[v - 1] = t;
}

template<class ET, class WT>
ET AdjListUndirGraph<ET, WT>::GetElem(int v)
{
	AdjListUndirGraphVex<ET, WT> e;
	e = vexTable[v - 1];
	return e.data;
}



template<class ET, class WT>
int AdjListUndirGraph<ET, WT>::FirstAdjVex(int v)
{
	if (v<1 || v>vexNum)
		throw Error("v不合法！");
	if (vexTable[v - 1].firstarc == NULL)		//把这里的.换成->试一下
		return -1;
	else
		return vexTable[v - 1].firstarc->adjVex;	//看一下
}

template<class ET, class WT>
int AdjListUndirGraph<ET, WT>::NextAdgVex(int v1, int v2)
{
	if (v1<1 || v1>vexNum)
		throw Error("v1不合法！");
	if (v2<1 || v2>vexNum)
		throw Error("v2不合法！");
	if (v1 == v2)
		throw Error("v1不能等于v2!");
	AdjListUndirGraphArc<WT> *p = vexTable[v1 - 1].firstarc;
	while (p != NULL && p->adjVex != v2)
		p = p->nextarc;
	if (p == NULL || p->nextarc == NULL)
		return -1;
	else
		return p->nextarc->adjVex;
}

template<class ET, class WT>
void AdjListUndirGraph<ET, WT>::InsertVex(const ET & d)
{
	if (vexNum == vexMaxNum)
		throw Error("图的顶点数目不能超过允许的最大数目！");
	vexTable[vexNum - 1].data = d;
	vexTable[vexNum - 1].firstarc = NULL;
	tag[vexNum - 1] = 0;
	vexNum++;
}

template<class ET, class WT>
void AdjListUndirGraph<ET, WT>::InsertArc(int v1, int v2, WT w)
{
	if (v1<1 || v1>vexNum)
		throw Error("v1不合法！");
	if (v2<1 || v2>vexNum)
		throw Error("v2不合法！");
	if (v1 == v2)
		throw Error("v1不能等于v2！");
	if (w == infinity)
		throw Error("权重w不能无穷大！");
	AdjListUndirGraphArc<WT> *p;
	p = vexTable[v1 - 1].firstarc;
	vexTable[v1 - 1].firstarc = new AdjListUndirGraphArc<WT>(v2, w, p);
	p = vexTable[v2 - 1].firstarc;
	vexTable[v2 - 1].firstarc = new AdjListUndirGraphArc<WT>(v1, w, p);
	arcNum++;
}

template<class ET, class WT>
void AdjListUndirGraph<ET, WT>::DeletVex(const ET & d)
{

	vexNum--;
}

template<class ET, class WT>
void AdjListUndirGraph<ET, WT>::DeletArc(int v1, int v2)
{
	if (v1<1 || v1>vexNum)
		throw Error("v1不合法！");
	if (v2<1 || v2>vexNum)
		throw Error("v2不合法！");
	if (v1 == v2)
		throw Error("v1不能等于v2!");
	AdjListUndirGraphArc<WT> *p, *q;
	p = vexTable[v1 - 1].firstarc;  //指向删除弧节点的指针
	while (p->adjVex != v2 && p->nextarc != NULL)  //找出v1中的弧节点
	{
		q = p;
		p = p->nextarc;
	}
	if (p->nextarc != NULL)  //删除v1中的弧节点
	{
		if (p == vexTable[v1 - 1].firstarc)  //若弧节点为第一个弧节点
			vexTable[v1 - 1].firstarc = p->nextarc;
		else			//不为第一个弧节点
			q->nextarc = p->nextarc;
		delete p;
	}
	p = vexTable[v2 - 1].firstarc;
	while (p->adjVex != v1 && p->nextarc != NULL)  //找出v2中的弧节点
	{
		q = p;
		p = p->nextarc;
	}
	if (p->nextarc != NULL)  //删除v2中的弧节点
	{
		if (p == vexTable[v2 - 1].firstarc)  //若弧节点为第一个弧节点
			vexTable[v2 - 1].firstarc = p->nextarc;
		else
			q->nextarc = p->nextarc;
		delete p;
	}
	arcNum--;
}
