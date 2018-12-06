#pragma once
#include<string>
#include<iostream>
template<class WT>
struct AdjListUndirGraphArc
{
	int adjVex;  //��ָ��Ķ������
	WT weight;  //����Ȩ��
	AdjListUndirGraphArc<WT> *nextarc;  //������һ����

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