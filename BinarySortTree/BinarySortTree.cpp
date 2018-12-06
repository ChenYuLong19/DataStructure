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
	BinaryTreeNode<T> *p = root;   //ָ��ǰ���ҵĽ��,û�в��ҵ�����ֵΪ��
	f = NULL;  //ָ���׽��
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
	BinaryTreeNode<T> *f;  //ָ�򱻲��ҽ��ĸ��׽��
	if (Find(e, f) == NULL)   //û�в��ҵ������Ԫ��,���Բ���
	{
		BinaryTreeNode<T> *p;
		p = new BinaryTreeNode<T>(e);
		if (IsEmpty())
			root = p; /*���������root->data = e;*/
		else if (e < f->data)
			f->leftChild = p;
		else
			f->rightChild = p;  //��e����f->data
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
	if (p->leftChild == NULL && p->rightChild == NULL)  //pΪҶ�ӽ��
	{
		delete p;
		p = NULL; /*����û�и�ɾ����ָ�븴��ֵ������ɾ����ı�������----------------------*/
	}
	else if (p->leftChild == NULL)  //p��������Ϊ��
	{
		tmPtr = p;
		p = p->rightChild;
		delete tmPtr;
	}
	else if (p->rightChild == NULL)  //p��������Ϊ��
	{
		tmPtr = p;
		p = p->leftChild;
		delete tmPtr;
	}
	else  //������������Ϊ��
	{
		tmPf = p;
		tmPtr = p->leftChild; //������������������Ԫ��
		while (tmPtr->rightChild != NULL)
		{
			tmPf = tmPtr;
			tmPtr = tmPtr->rightChild;
		}
		p->data = tmPtr->data; //��Ҫɾ����������ǰ������ֵ��ֵ��Ҫɾ�����
		if (tmPf->rightChild == tmPtr)
			Delete(tmPf->rightChild);
		else
			Delete(tmPf->leftChild);  //��������tmPf����Ҫɾ������ʱ��tmPtr
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
