#include<iostream>
#include"LinkList.cpp"
using namespace std;
int main()
{
	int v[5], arr[10], a;
	

	cout << "�����һ��������";
	for (int i = 0; i < 5; i++)
		cin >> v[i];
	LinkList<int> list1(v, 5);
	cout << "�����������ӦΪ��";
	list1.Traverse();
	cout << endl;


	cout << "����ڶ���������";
	for (int i = 0; i < 5; i++)
		cin >> v[i];
	LinkList<int> list2(v, 5);
	cout << "�����������ӦΪ��";
	list2.Traverse(); 
	cout << endl;


	/* ͬ����Ľ������������һ��������
	for (int i = 1; i <= 5; i++)
	{
		list1.Get(i, a); arr[i - 1] = a;
	}
	for (int i = 1; i <= 5; i++)
	{
		list2.Get(i, a); arr[i + 4] = a;
	}*/
	for (int i = 0; i < 10; i++)//�������������һ��������
	{
		if (i < 5) { list1.Get(i + 1, a); arr[i] = a; }
		else { list2.Get(i - 4, a); arr[i] = a; }
	}
	LinkList<int> list3(arr, 10);
	cout << "�ϲ���������������źõĽ��ӦΪ��" << endl;
	list3.Traverse();
	cout << endl;
	system("pause");

	return 0;
}

