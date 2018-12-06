#pragma once
#include<iostream>
template<class T>
struct Node
{
	T data;
	Node<T> *next;

	Node();  //�޲ν�㹹�캯��
	Node(T e, Node<T> *link = NULL);  //�вν�㹹�캯��
};
template<class T>
Node<T>::Node()
{
	next = NULL;
}
template<class T>
Node<T>::Node(T e, Node<T> *link)
{
	data = e;
	next = link;
}