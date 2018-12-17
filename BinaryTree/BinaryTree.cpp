#include<stack>
#include "BinaryTree.h"
#include<iostream>
using namespace std;

//�޲ι��캯��
template<class ElemType>
BinaryTree<ElemType>::BinaryTree()
{
	root = new BinTreeNode<ElemType>;
}
//�вι��캯��
template<class ElemType>
BinaryTree<ElemType>::BinaryTree(const ElemType &e)
{
	root = new BinTreeNode<ElemType>(e, NULL, NULL);
}
//��������
template<class ElemType>
BinaryTree< ElemType>::~BinaryTree()
{
	Clear(root);
}
//�����������
template<class ElemType>
void BinaryTree<ElemType>::Clear(BinTreeNode<ElemType> * &r)
{
	if (r != NULL)
	{
		Clear(r->leftChild);
		Clear(r->rightChild);
		delete r;
		r = NULL;
	}
}


template<class ElemType>
void BinaryTree<ElemType>::CreateBinTree()
{
	CreateBinTree(root);
}
template<class ElemType>
void BinaryTree<ElemType>::CreateBinTree(BinTreeNode<ElemType>* &r)
{
	ElemType ch;
	std::cin >> ch;
	if (ch == '#') r = NULL;
	else
	{
		r = new BinTreeNode<ElemType>(ch);
		CreateBinTree(r->leftChild);
		CreateBinTree(r->rightChild);
	}
}


//��������ĸ�
template<class ElemType>
BinTreeNode<ElemType> * BinaryTree<ElemType>::GetRoot()
{
	return root;
}
//�������
template<class ElemType>
void BinaryTree<ElemType>::PerOrder()const//��ջΪ�����洢�ṹʵ�ֶ�������ǰ��ǵݹ��㷨
{
	stack<BinTreeNode<ElemType>*>s;
	BinTreeNode<ElemType> *r = root;

	while (r != NULL || !s.empty())
	{
		while (r != NULL)
		{
			s.push(r);
			cout << r->data << endl;
			r = r->leftChild;
		}
		r = s.top();
		s.pop();
		r = r->rightChild;

	}
}
template<class ElemType>
void BinaryTree<ElemType>::PerOrder(BinTreeNode<ElemType> *r)const
{
	/*stack<ElemType> s;
	BinTreeNode<ElemType> *p=root;
	whlie(!s.empty||p)
	{
		while (p)
		{
			s.push(*p);
			cout << p->data();
			p = p->leftChild();
		}
		p = s.top();
		s.pop();
		p = p->rightChild();
	}*/

		//��ջΪ�����洢�ṹʵ�ֶ�������ǰ��ǵݹ��㷨
}


//�������
template<class ElemType>
void BinaryTree<ElemType>::InOrder()const
{
	InOrder(root);
}
template<class ElemType>
void BinaryTree<ElemType>::InOrder(BinTreeNode<ElemType> *r)const
{
	if (r != NULL)
	{
		InOrder(r->leftChild);
		std::cout << r->data << ' ';
		InOrder(r->rightChild);
	}
}


//�������
template<class ElemType>
void BinaryTree<ElemType>::PostOrder()const
{
	PostOrder(root);
}
template<class ElemType>
void BinaryTree<ElemType>::PostOrder(BinTreeNode<ElemType> *r)const
{
	if (r != NULL)
	{
		PostOrder(r->leftChild);
		PostOrder(r->rightChild);
		std::cout << r->data << ' ';
	}
}


//��������ĸ߶�
template<class ElemType>
int BinaryTree<ElemType>::Height()const
{
	return Height(root);
}
template<class ElemType>
int BinaryTree< ElemType>::Height(const BinTreeNode<ElemType> *r)const
{
	if (r == NULL)
		return 0;
	else
	{
		int lHeight, rHeight;
		lHeight = Height(r->leftChild);
		rHeight = Height(r->rightChild);
		return (lHeight > rHeight ? lHeight : rHeight) + 1;
	}
}


//���������Ҷ����Ŀ
template<class ElemType>
int BinaryTree<ElemType>::Leaf()const
{
	return Leaf(root);
}
template<class ElemType>
int BinaryTree<ElemType>::Leaf(const BinTreeNode<ElemType> *r)const
{
	static int count = 0;
	if (r == NULL)
		return 0;
	else
	{
		Leaf(r->leftChild);
		Leaf(r->rightChild);
		if (r->leftChild == NULL && r->rightChild == NULL) count++;
		return count;
	}
}