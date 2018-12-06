#include<iostream>
#include"LinkList.cpp"
using namespace std;
template<class T>
void visit(const T &e)
{
	cout << e << ' ';
}
int main()
{
	int v[5], arr[10], a;
	//创建第一个链表
	for (int i = 0; i < 5; i++)
		cin >> v[i];
	LinkList<int> list1(v, 5);
	list1.Traverse(&visit);  //输出链表1的元素
	//创建第二个链表
	for (int i = 0; i < 5; i++)
		cin >> v[i];
	LinkList<int> list2(v, 5);
	list2.Traverse(&visit);  //输出链表2的元素
	system("pause");
	//创建第三个链表
	for (int i = 1; i <= 5; i++)
	{
		list1.Get(i, a); arr[i - 1] = a;
	}
	for (int i = 1; i <= 5; i++)
	{
		list2.Get(i, a); arr[i + 4] = a;
	}
	//for (int i = 0; i < 10; i++)//将两个链表放入一个数组中
	//{
	//	if (i < 5) { list1.Get(i + 1, a); arr[i] = a; }
	//	else { list2.Get(i - 4, a); arr[i] = a; }
	//}
	system("pause");
	LinkList<int> list3(arr, 10);
	list3.Traverse(&visit);//输出链表3的元素
	system("pause");

	return 0;
}

