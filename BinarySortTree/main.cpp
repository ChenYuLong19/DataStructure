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

	cout << endl << "输入要删除的整数：";
	int d;
	cin >> d;
	BinST.Delete(d);
	cout << "输出删除后的中序遍历序列应为：";
	BinST.InOrder();  //中序遍历删除后的的二叉排序树
	cout << endl;
	system("pause");
	return 0;
}