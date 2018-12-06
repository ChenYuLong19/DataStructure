#pragma once
#include"BinaryTreeNode.h"
template<class ElemType>
class BinaryTree
{
protected:
	//�����������ݳ�Ա:
	BinTreeNode< ElemType> *root;

	//��������:
	BinTreeNode< ElemType> *CopyTree(BinTreeNode< ElemType> *t);//���ƶ�����t
	void Destory(BinTreeNode< ElemType> *&r); //ɾ����rΪ�����Ķ����� 
	void PerOrder(BinTreeNode< ElemType> *r, void(*visit)(const ElemType &))const;//���������rΪ�����Ķ�����
	void InOrder(BinTreeNode< ElemType> *r, void(*visit)(const ElemType &))const;//���������rΪ�����Ķ�����
	void PostOrder(BinTreeNode< ElemType> *r, void(*visit)(const ElemType &))const;//���������rΪ�����Ķ�����
	int Height(const BinTreeNode< ElemType> *r)const;//����rΪ���Ķ������ĸ߶�
	int Leaf(const BinTreeNode<ElemType> *r)const;//��һrΪ���Ķ������ĸ߶�
	int NodeCount(BinTreeNode< ElemType> *r)const;//����rΪ���Ķ������Ľ�����
	BinTreeNode< ElemType> * Parent(BinTreeNode< ElemType> *r, BinaryTree< ElemType> *p)const;//����rΪ���Ķ���������p��˫��
	void CreateBinTree(BinTreeNode<ElemType>* &r);//����������
public:
	//�������ĳ�Ա����:
	BinaryTree();  //�޲ι��캯��
	BinaryTree(const ElemType &e);//������eΪ���Ķ�����
	virtual ~BinaryTree();  //��������
	void Clear(BinTreeNode<ElemType> * &r);//�����������
	void CreateBinTree();//����������
	BinTreeNode<ElemType> * GetRoot();//��������ĸ�
	void PerOrder(void(*visit)(const ElemType &))const;//���������������
	void InOrder(void(*visit)(const ElemType &))const;//���������������
	void PostOrder(void(*visit)(const ElemType &))const;//�������ĺ������
	int Height()const;//��������ĸ߶�(���)
	int Leaf()const;//���������Ҷ����Ŀ

};