#pragma once
#include"AdjListUndirGraphArc.h"
template<class ET, class WT>
struct AdjListUndirGraphVex
{
	ET data;						//数据元素值
	AdjListUndirGraphArc<WT> *firstarc;		//指向邻接链表边结点的指针

	AdjListUndirGraphVex();
	AdjListUndirGraphVex(ET val, AdjListUndirGraphArc<WT> *adj = NULL);
};
template<class ET, class WT>
AdjListUndirGraphVex<ET, WT>::AdjListUndirGraphVex()
{
	firstarc = NULL;
}
template<class ET, class WT>
AdjListUndirGraphVex<ET, WT>::AdjListUndirGraphVex(ET val, AdjListUndirGraphArc<WT> *adj)
{
	data = val;
	firstarc = adj;
}