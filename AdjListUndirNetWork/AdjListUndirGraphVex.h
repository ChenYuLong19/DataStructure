#pragma once
#include"AdjListUndirGraphArc.h"
template<class ET, class WT>
struct AdjListUndirGraphVex
{
	ET data;						//����Ԫ��ֵ
	AdjListUndirGraphArc<WT> *firstarc;		//ָ���ڽ�����߽���ָ��

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