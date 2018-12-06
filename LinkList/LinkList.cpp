#include"LinkList.h"
#include<assert.h>

template<class T>
LinkList<T>::LinkList()  //�޲ι��캯��
{
	head = new Node<T>;
	length = 0;
}

template<class T>
LinkList<T>::LinkList(T v[], int n)  
{
	int k;
	for (int i = 0; i < n - 1; i++)  //������v�е�ֵ��������
	{
		k = i;  //kΪ��i������Сֵ���±�
		for (int j = i + 1; j < n; j++)
			if (v[j] < v[k])
				k = j;
		T t = v[i]; v[i] = v[k]; v[k] = t;
		//v[i] = v[i] + v[k]; v[k] = v[i] - v[k]; v[i] = v[i] - v[k];//�ޱ�����������
	}
	Node<T> *p;
	p = head = new Node<T>;
	for (int i = 0; i < n; i++)
	{
		p->next = new Node<T>(v[i], NULL);
		assert(p->next);  //����Ԫ�ؽ��ʧ��,��ֹ��������
		p = p->next;
	}
	length = n;
}

template<class T>
LinkList<T>::~LinkList()  //��������
{
	Clear();  //��յ�����
	delete head;  //�ͷ�ͷ���
}

template<class T>
void LinkList<T>::Clear()
{
	Node<T> *p = head->next;
	while (p->next != NULL)
	{
		head->next = p->next;
		delete p;
		p = head->next;
	}
	length = 0;
}

template<class T>
void LinkList<T>::Traverse()const  //��������
{
	Node<T> *p = head->next;
	while (p != NULL)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
}

template<class T>
Status LinkList<T>::Insert(int i, const T &e)
{
	if (i<1 || i>length + 1)
		return fail;
	else
	{
		Node<T> *p = head, *q;
		for (int count = 1; count < i; count++)
			p = p->next;
		q = new Node<T>(e, p->next);
		p->next = q;
		length++;
		return success;
	}
}

template<class T>
Status LinkList<T>::Delete(int i, T &e)
{
	if (i<1 || i>length + 1)
		return fail;
	else
	{
		Node<T> *p = head, *q;
		for (int count = 1; count < i; count++)
			p = p->next;
		q = p->next;
		p->next = q->next;
		e = q->date;
		length--;
		delete q;
		return success;
	}
}

template<class T>
Status LinkList<T>::Get(int i, T &e)const
{
	if (i<1 || i>length + 1)
		return fail;
	else
	{
		Node<T> *p = head->next;
		for (int count = 1; count < i; count++)
			p = p->next;
		e = p->data;
		return success;
	}
}
