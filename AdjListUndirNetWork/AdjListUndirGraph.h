#pragma once
#include"AdjListUndirGraphVex.h"
#include"AdjListUndirGraphArc.h"
#include<string>
using namespace std;
template<class ET, class WT>
class AdjListUndirGraph
{
protected:
	int vexNum, vexMaxNum, arcNum;		//������Ŀ����󶥵���Ŀ������
	AdjListUndirGraphVex<ET, WT> *vexTable;	//�����
	mutable int *tag;		    //��־���飬����ö���û�з�����0�������˱��1
	WT infinity;			//������ֵ

public:
	AdjListUndirGraph(ET es[], int vertexNum, int vertexMaxNum /*= DEFAULIT_SIZE*/, WT infinit/* = (WT)DEFAULT_INFINITY*/);
	//����������es[]Ϊ�������ݣ��������ΪvertexNum������������ĿΪvertexMaxNum������Ϊ0��������
	AdjListUndirGraph(int vertexMaxNum /*= DEFAULIT_SIZE*/, WT infinit/* = (WT)DEFAULIT_INFINITY*/);
	//��������Ķ��������ĿΪvertexMaxNum������Ϊ0��������
	~AdjListUndirGraph();
	void Clear();
	bool IsEmpty();
	string Error(string str);

	void DFS(int v);  //���������������
	void DFSTraverse();  //���������������


	void SetTag(int v, int t);  //���÷��ʱ�־
	ET GetElem(int v);  //ȡ����v

	int FirstAdjVex(int v);			//���������ж���v�ĵ�һ���ڽӵ�
	int NextAdgVex(int v1, int v2);		//�󶥵�v1�������v2����һ���ڽӵ�

	void InsertVex(const ET &d);		//����ֵΪd�Ķ���
	void InsertArc(int v1, int v2, WT w);		//����Ӷ���v1��v2��ȨΪw�Ļ�

	void DeletVex(const ET &d);			//ɾ��ֵΪd�Ķ���
	void DeletArc(int v1, int v2);		//ɾ��v1��v2��ȨΪw�Ļ�
};