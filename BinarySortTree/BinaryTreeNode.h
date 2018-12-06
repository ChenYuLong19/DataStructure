#pragma once
#include<iostream>
template<class T>
struct BinaryTreeNode
{
	T data;
	BinaryTreeNode<T> *leftChild;
	BinaryTreeNode<T> *rightChild;

public:
	BinaryTreeNode();
	BinaryTreeNode(const T d, BinaryTreeNode<T> *lChild = NULL, BinaryTreeNode<T> *rChild = NULL);
};
template<class T>
BinaryTreeNode<T>::BinaryTreeNode()
{
	leftChild = rightChild = NULL;  //data 为什么没有默认值
}
template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T d, BinaryTreeNode<T> *lChild, BinaryTreeNode<T> *rChild)
{
	data = d;
	leftChild = lChild;
	rightChild = rChild;
}