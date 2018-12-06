#pragma once
#include<iostream>
template<class T>
struct Node
{
	T data;
	Node<T> *next;

	Node();  //无参结点构造函数
	Node(T e, Node<T> *link = NULL);  //有参结点构造函数
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