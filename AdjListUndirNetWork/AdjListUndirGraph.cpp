#include"AdjListUndirGraph.h"
using namespace std;
template<class ET, class WT>
AdjListUndirGraph<ET, WT>::AdjListUndirGraph(ET es[], int vertexNum, int vertexMaxNum, WT infinit)
{
	if (vertexMaxNum < 0)
		throw Error("����Ķ����������Ŀ����С��0��");
	if (vertexNum > vertexMaxNum)
		throw Error("�������Ŀ���ܴ��ڶ�������������Ŀ��");
	vexNum = vertexNum;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;
	infinity = infinit;
	tag = new int[vertexMaxNum];
	vexTable = new AdjListUndirGraphVex<ET, WT>[vertexMaxNum];
	for (int v = 0; v < vertexNum; v++)
	{
		tag[v] = 0; //Ĭ�϶���û�б�����
		vexTable[v].data = es[v];
		vexTable[v].firstarc = NULL;
	}
}
template<class ET, class WT>
AdjListUndirGraph<ET, WT>::AdjListUndirGraph(int vertexMaxNum, WT infinit)
{
	if (vertexMaxNum < 0)
		throw Error("����Ķ���������Ŀ����С��0��");
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
	tag[v - 1] = 1;  //����v�ķ��ʱ�־Ϊ�ѷ���1
	cout << vexTable[v - 1].data << " "; //���ʶ���v
	for (int w = FirstAdjVex(v); w != -1; w = NextAdgVex(v, w))
		if (tag[w - 1] == 0)
			DFS(w);  //�ݹ��Ҹö������һ����
}

template<class ET, class WT>
void AdjListUndirGraph<ET, WT>::DFSTraverse()
{
	for (int v = 0; v < vexNum; v++)
		tag[v] = 0;  /*���v�������0��ʼ�ģ���������Ϊ�Ƕ���ı�Ž�����Ҫ��1*/
	for (int v = 0; v < vexNum; v++)
		if (tag[v] == 0)  //û�з���
			DFS(v + 1);  /*��0��ʼ�ı�ž����붥����Ҫ��1*/
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
		throw Error("v���Ϸ���");
	if (vexTable[v - 1].firstarc == NULL)		//�������.����->��һ��
		return -1;
	else
		return vexTable[v - 1].firstarc->adjVex;	//��һ��
}

template<class ET, class WT>
int AdjListUndirGraph<ET, WT>::NextAdgVex(int v1, int v2)
{
	if (v1<1 || v1>vexNum)
		throw Error("v1���Ϸ���");
	if (v2<1 || v2>vexNum)
		throw Error("v2���Ϸ���");
	if (v1 == v2)
		throw Error("v1���ܵ���v2!");
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
		throw Error("ͼ�Ķ�����Ŀ���ܳ�������������Ŀ��");
	vexTable[vexNum - 1].data = d;
	vexTable[vexNum - 1].firstarc = NULL;
	tag[vexNum - 1] = 0;
	vexNum++;
}

template<class ET, class WT>
void AdjListUndirGraph<ET, WT>::InsertArc(int v1, int v2, WT w)
{
	if (v1<1 || v1>vexNum)
		throw Error("v1���Ϸ���");
	if (v2<1 || v2>vexNum)
		throw Error("v2���Ϸ���");
	if (v1 == v2)
		throw Error("v1���ܵ���v2��");
	if (w == infinity)
		throw Error("Ȩ��w���������");
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
		throw Error("v1���Ϸ���");
	if (v2<1 || v2>vexNum)
		throw Error("v2���Ϸ���");
	if (v1 == v2)
		throw Error("v1���ܵ���v2!");
	AdjListUndirGraphArc<WT> *p, *q;
	p = vexTable[v1 - 1].firstarc;  //ָ��ɾ�����ڵ��ָ��
	while (p->adjVex != v2 && p->nextarc != NULL)  //�ҳ�v1�еĻ��ڵ�
	{
		q = p;
		p = p->nextarc;
	}
	if (p->nextarc != NULL)  //ɾ��v1�еĻ��ڵ�
	{
		if (p == vexTable[v1 - 1].firstarc)  //�����ڵ�Ϊ��һ�����ڵ�
			vexTable[v1 - 1].firstarc = p->nextarc;
		else			//��Ϊ��һ�����ڵ�
			q->nextarc = p->nextarc;
		delete p;
	}
	p = vexTable[v2 - 1].firstarc;
	while (p->adjVex != v1 && p->nextarc != NULL)  //�ҳ�v2�еĻ��ڵ�
	{
		q = p;
		p = p->nextarc;
	}
	if (p->nextarc != NULL)  //ɾ��v2�еĻ��ڵ�
	{
		if (p == vexTable[v2 - 1].firstarc)  //�����ڵ�Ϊ��һ�����ڵ�
			vexTable[v2 - 1].firstarc = p->nextarc;
		else
			q->nextarc = p->nextarc;
		delete p;
	}
	arcNum--;
}
