#pragma once
#include"BinaryTreeNode.h"
template<class T>class BinarySortTree
{
	BinaryTreeNode<T> *root;

public:
	BinarySortTree();
	~BinarySortTree();
	void Clear(BinaryTreeNode<T> *&r);

	BinaryTreeNode<T> *Find(const T &key, BinaryTreeNode<T> *&f);

	bool IsEmpty();
	bool Insert(const T &e);  //����Ԫ��e
	bool Delete(const T &e);  //����Ҫɾ����Ԫ��e
	void Delete(BinaryTreeNode<T> *&p);  //ɾ��ָ��p�Ľ��
	void InOrder();  //�������
	void InOrder(BinaryTreeNode<T> *r);

};