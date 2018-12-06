#include<stack>
#include "BinaryTree.h"

//无参构造函数
template<class ElemType>
BinaryTree<ElemType>::BinaryTree()
{
	root = new BinTreeNode<ElemType>;
}
//有参构造函数
template<class ElemType>
BinaryTree<ElemType>::BinaryTree(const ElemType &e)
{
	root = new BinTreeNode<ElemType>(e, NULL, NULL);
}
//析构函数
template<class ElemType>
BinaryTree< ElemType>::~BinaryTree()
{
	Clear(root);
}
//将二叉树清空
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


//求二叉树的根
template<class ElemType>
BinTreeNode<ElemType> * BinaryTree<ElemType>::GetRoot()
{
	return root;
}
//先序遍历
template<class ElemType>
void BinaryTree<ElemType>::PerOrder()const
{
	PerOrder(root);
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
			cout << p->date();
			p = p->leftChild();
		}
		p = s.top();
		s.pop();
		p = p->rightChild();
	}*/

		//以栈为辅助存储结构实现二叉树的前序非递归算法
}


//中序遍历
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
		std::cout << r->date << ' ';
		InOrder(r->rightChild);
	}
}


//后序遍历
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
		std::cout << r->date << ' ';
	}
}


//求二叉树的高度
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


//求二叉树的叶子数目
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