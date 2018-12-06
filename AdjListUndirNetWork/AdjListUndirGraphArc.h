#pragma once
#include<string>
#include<iostream>
template<class WT>
struct AdjListUndirGraphArc
{
	int adjVex;  //弧指向的顶点序号
	WT weight;  //弧的权重
	AdjListUndirGraphArc<WT> *nextarc;  //弧的下一个弧

	AdjListUndirGraphArc();
	AdjListUndirGraphArc(int v, WT w, AdjListUndirGraphArc<WT> *next = NULL);
};
template<class WT>
AdjListUndirGraphArc<WT>::AdjListUndirGraphArc()
{
	adjVex = -1;
}
template<class WT>
AdjListUndirGraphArc<WT>::AdjListUndirGraphArc(int v, WT w, AdjListUndirGraphArc<WT> *next)
{
	adjVex = v;
	weight = w;
	nextarc = next;
}