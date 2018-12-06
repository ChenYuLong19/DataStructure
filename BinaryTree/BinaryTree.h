#pragma once
#include"BinaryTreeNode.h"
template<class ElemType>
class BinaryTree
{
protected:
	//�����������ݳ�Ա:
	BinTreeNode< ElemType> *root;

	//��������:
	void PerOrder(BinTreeNode< ElemType> *r)const;//���������rΪ�����Ķ�����
	void InOrder(BinTreeNode< ElemType> *r)const;//���������rΪ�����Ķ�����
	void PostOrder(BinTreeNode< ElemType> *r)const;//���������rΪ�����Ķ�����
	int Height(const BinTreeNode< ElemType> *r)const;//����rΪ���Ķ������ĸ߶�
	int Leaf(const BinTreeNode<ElemType> *r)const;//��һrΪ���Ķ������ĸ߶�
	void CreateBinTree(BinTreeNode<ElemType>* &r);//����������
public:
	//�������ĳ�Ա����:
	BinaryTree();  //�޲ι��캯��
	BinaryTree(const ElemType &e);//������eΪ���Ķ�����
	virtual ~BinaryTree();  //��������
	void Clear(BinTreeNode<ElemType> * &r);

	void CreateBinTree();//����������
	BinTreeNode<ElemType> * GetRoot();//��������ĸ�
	void PerOrder()const;//���������������
	void InOrder()const;//���������������
	void PostOrder()const;//�������ĺ������
	int Height()const;//��������ĸ߶�(���)
	int Leaf()const;//���������Ҷ����Ŀ

};