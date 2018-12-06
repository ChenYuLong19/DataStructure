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
	bool Insert(const T &e);  //插入元素e
	bool Delete(const T &e);  //查找要删除的元素e
	void Delete(BinaryTreeNode<T> *&p);  //删除指向p的结点
	void InOrder();  //中序遍历
	void InOrder(BinaryTreeNode<T> *r);

};