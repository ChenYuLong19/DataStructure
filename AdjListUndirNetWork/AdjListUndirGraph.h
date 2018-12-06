#pragma once
#include"AdjListUndirGraphVex.h"
#include"AdjListUndirGraphArc.h"
#include<string>
using namespace std;
template<class ET, class WT>
class AdjListUndirGraph
{
protected:
	int vexNum, vexMaxNum, arcNum;		//顶点数目，最大顶点数目，弧数
	AdjListUndirGraphVex<ET, WT> *vexTable;	//顶点表
	mutable int *tag;		    //标志数组，如果该顶点没有访问是0，访问了变成1
	WT infinity;			//无穷大的值

public:
	AdjListUndirGraph(ET es[], int vertexNum, int vertexMaxNum /*= DEFAULIT_SIZE*/, WT infinit/* = (WT)DEFAULT_INFINITY*/);
	//构造以数组es[]为顶点数据，顶点个数为vertexNum，允许的最大数目为vertexMaxNum，弧数为0的又向网
	AdjListUndirGraph(int vertexMaxNum /*= DEFAULIT_SIZE*/, WT infinit/* = (WT)DEFAULIT_INFINITY*/);
	//构造允许的顶点最大数目为vertexMaxNum，弧数为0的有向网
	~AdjListUndirGraph();
	void Clear();
	bool IsEmpty();
	string Error(string str);

	void DFS(int v);  //深度优先搜索函数
	void DFSTraverse();  //深度优先搜索遍历


	void SetTag(int v, int t);  //设置访问标志
	ET GetElem(int v);  //取顶点v

	int FirstAdjVex(int v);			//求又向网中顶点v的第一个邻接点
	int NextAdgVex(int v1, int v2);		//求顶点v1的相对于v2的下一个邻接点

	void InsertVex(const ET &d);		//插入值为d的顶点
	void InsertArc(int v1, int v2, WT w);		//插入从顶点v1到v2、权为w的弧

	void DeletVex(const ET &d);			//删除值为d的顶点
	void DeletArc(int v1, int v2);		//删除v1到v2、权为w的弧
};