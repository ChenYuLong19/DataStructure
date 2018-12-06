#include<iostream>
#include"LinkList.cpp"
using namespace std;
int main()
{
	int v[5], arr[10], a;
	

	cout << "输入第一组整数：";
	for (int i = 0; i < 5; i++)
		cin >> v[i];
	LinkList<int> list1(v, 5);
	cout << "输出排序单链表应为：";
	list1.Traverse();
	cout << endl;


	cout << "输入第二组整数：";
	for (int i = 0; i < 5; i++)
		cin >> v[i];
	LinkList<int> list2(v, 5);
	cout << "输出排序单链表应为：";
	list2.Traverse(); 
	cout << endl;


	/* 同下面的将两个链表放入一个数组中
	for (int i = 1; i <= 5; i++)
	{
		list1.Get(i, a); arr[i - 1] = a;
	}
	for (int i = 1; i <= 5; i++)
	{
		list2.Get(i, a); arr[i + 4] = a;
	}*/
	for (int i = 0; i < 10; i++)//将两个链表放入一个数组中
	{
		if (i < 5) { list1.Get(i + 1, a); arr[i] = a; }
		else { list2.Get(i - 4, a); arr[i] = a; }
	}
	LinkList<int> list3(arr, 10);
	cout << "合并两个单链表，输出排好的结果应为：" << endl;
	list3.Traverse();
	cout << endl;
	system("pause");

	return 0;
}

