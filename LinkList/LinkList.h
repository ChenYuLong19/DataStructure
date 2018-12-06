#pragma once
#include"Node.h"
enum Status { success, fali };
template<class T>
class LinkList
{
protected:
	Node<T> *head;  //头结点指针
	int length;		//元素个数
public:
	LinkList();
	LinkList(T v[], int n);
	virtual  ~LinkList();
	void Clear();
	void Traverse(void(*visit)(const T &))const;
	Status Insert(int i, const T &e);
	Status Delete(int i, T &e);
	Status Get(int i, T &e)const;

};