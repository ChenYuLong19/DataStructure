#pragma once
#include"BinaryTreeNode.h"
template<class ElemType>
class BinaryTree
{
protected:
	//二叉树的数据成员:
	BinTreeNode< ElemType> *root;

	//辅助函数:
	BinTreeNode< ElemType> *CopyTree(BinTreeNode< ElemType> *t);//复制二叉树t
	void Destory(BinTreeNode< ElemType> *&r); //删除以r为根结点的二叉树 
	void PerOrder(BinTreeNode< ElemType> *r, void(*visit)(const ElemType &))const;//先序遍历以r为根结点的二叉树
	void InOrder(BinTreeNode< ElemType> *r, void(*visit)(const ElemType &))const;//中序遍历以r为根结点的二叉树
	void PostOrder(BinTreeNode< ElemType> *r, void(*visit)(const ElemType &))const;//后序遍历以r为根结点的二叉树
	int Height(const BinTreeNode< ElemType> *r)const;//求以r为根的二叉树的高度
	int Leaf(const BinTreeNode<ElemType> *r)const;//求一r为根的二叉树的高度
	int NodeCount(BinTreeNode< ElemType> *r)const;//求以r为根的二叉树的结点个数
	BinTreeNode< ElemType> * Parent(BinTreeNode< ElemType> *r, BinaryTree< ElemType> *p)const;//求以r为根的二叉树中求p的双亲
	void CreateBinTree(BinTreeNode<ElemType>* &r);//建立二叉树
public:
	//二叉树的成员函数:
	BinaryTree();  //无参构造函数
	BinaryTree(const ElemType &e);//构造以e为根的二叉树
	virtual ~BinaryTree();  //析构函数
	void Clear(BinTreeNode<ElemType> * &r);//将二叉树清空
	void CreateBinTree();//建立二叉树
	BinTreeNode<ElemType> * GetRoot();//求二叉树的根
	void PerOrder(void(*visit)(const ElemType &))const;//二叉树的先序遍历
	void InOrder(void(*visit)(const ElemType &))const;//二叉树的中序遍历
	void PostOrder(void(*visit)(const ElemType &))const;//二叉树的后序遍历
	int Height()const;//求二叉树的高度(深度)
	int Leaf()const;//求二叉树的叶子数目

};