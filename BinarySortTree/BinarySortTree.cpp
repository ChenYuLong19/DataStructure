#include"BinarySortTree.h"
template<class T>BinarySortTree<T>::BinarySortTree()
{
	root = NULL;
}

template<class T>
BinarySortTree<T>::~BinarySortTree()
{
	Clear(root);
}

template<class T>
void BinarySortTree<T>::Clear(BinaryTreeNode<T>*& r)
{
	if (r != NULL)
	{
		Clear(r->leftChild);
		Clear(r->rightChild);
		delete r;
		r = NULL;
	}
}

template<class T>
BinaryTreeNode<T>* BinarySortTree<T>::Find(const T & key, BinaryTreeNode<T>*& f)
{
	BinaryTreeNode<T> *p = root;   //指向当前查找的结点,没有查找到返回值为空
	f = NULL;  //指向父亲结点
	while (p != NULL && p->data != key)
	{
		if (key < p->data)
		{
			f = p;
			p = p->leftChild;
		}
		else /*if (p->data < key)*/
		{
			f = p;
			p = p->rightChild;
		}
	}
	return p;
}

template<class T>
bool BinarySortTree<T>::IsEmpty()
{
	if (root == NULL)
		return true;
	else
		return false;
}

template<class T>
bool BinarySortTree<T>::Insert(const T & e)
{
	BinaryTreeNode<T> *f;  //指向被查找结点的父亲结点
	if (Find(e, f) == NULL)   //没有查找到插入的元素,可以插入
	{
		BinaryTreeNode<T> *p;
		p = new BinaryTreeNode<T>(e);
		if (IsEmpty())
			root = p; /*把这个改了root->data = e;*/
		else if (e < f->data)
			f->leftChild = p;
		else
			f->rightChild = p;  //当e大于f->data
		return true;
	}
	else
		return false;
}

template<class T>
bool BinarySortTree<T>::Delete(const T & e)
{
	BinaryTreeNode<T> *f, *p;
	p = Find(e, f);
	if (p != NULL)
	{
		Delete(p);
		return true;
	}
	else
		return false;
}

template<class T>
void BinarySortTree<T>::Delete(BinaryTreeNode<T>*& p)
{
	BinaryTreeNode<T> *tmPtr, *tmPf;
	if (p->leftChild == NULL && p->rightChild == NULL)  //p为叶子结点
	{
		delete p;
		p = NULL; /*这里没有给删除的指针复赋值，导致删除后的遍历出错----------------------*/
	}
	else if (p->leftChild == NULL)  //p的左子树为空
	{
		tmPtr = p;
		p = p->rightChild;
		delete tmPtr;
	}
	else if (p->rightChild == NULL)  //p的右子树为空
	{
		tmPtr = p;
		p = p->leftChild;
		delete tmPtr;
	}
	else  //左右子树都不为空
	{
		tmPf = p;
		tmPtr = p->leftChild; //查找左树中最大的数据元素
		while (tmPtr->rightChild != NULL)
		{
			tmPf = tmPtr;
			tmPtr = tmPtr->rightChild;
		}
		p->data = tmPtr->data; //将要删除结点的中序前躯结点的值赋值给要删除结点
		if (tmPf->rightChild == tmPtr)
			Delete(tmPf->rightChild);
		else
			Delete(tmPf->leftChild);  //当父类结点tmPf就是要删除结点的时候，tmPtr
	}
}

template<class T>
void BinarySortTree<T>::InOrder()
{
	InOrder(root);
}

template<class T>
void BinarySortTree<T>::InOrder(BinaryTreeNode<T>* r)
{
	if (r != NULL)
	{
		InOrder(r->leftChild);
		std::cout << r->data << ' ';
		InOrder(r->rightChild);
	}
}
