#pragma once
#include<iostream>
template<class ElemType>
struct BinTreeNode
{
	ElemType date;
	BinTreeNode<ElemType> *leftChild;
	BinTreeNode<ElemType> *rightChild;

	BinTreeNode();  //无参构造函数
	BinTreeNode(const ElemType &d, BinTreeNode< ElemType>*lChild = NULL, BinTreeNode< ElemType>*rChild = NULL);
};
template<class ElemType>
BinTreeNode<ElemType>::BinTreeNode()
{
	leftChild = rightChild = NULL;
}
template<class ElemType>
BinTreeNode< ElemType>::BinTreeNode(const ElemType &d, BinTreeNode< ElemType> *lChild, BinTreeNode< ElemType>*rChild)
{
	date = d;
	leftChild = lChild;
	rightChild = rChild;
}