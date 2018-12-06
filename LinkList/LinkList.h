#pragma once
#include"Node.h"
enum Status { success, fail };
template<class T>
class LinkList
{
protected:
	Node<T> *head;  //ͷ���ָ��
	int length;	  //Ԫ�ظ���
public:
	LinkList();
	LinkList(T v[], int n);
	virtual  ~LinkList();
	void Clear();
	void Traverse()const;
	Status Insert(int i, const T &e);
	Status Delete(int i, T &e);
	Status Get(int i, T &e)const;

};