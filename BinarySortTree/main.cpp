#include"BinarySortTree.cpp"
#include<iostream>
using namespace std;
int main()
{
	BinarySortTree<int> BinST;
	int arr[10] = { 67,13,11,88,45,9,60,20 };
	for (int i = 0; i < 8; i++)
	{
		BinST.Insert(arr[i]);
	}
	BinST.InOrder();

	cout << endl << "����Ҫɾ����������";
	int d;
	cin >> d;
	BinST.Delete(d);
	cout << "���ɾ����������������ӦΪ��";
	BinST.InOrder();  //�������ɾ����ĵĶ���������
	cout << endl;
	system("pause");
	return 0;
}