#include<iostream>
#include"BinaryTree.cpp"
using namespace std;
int  main()
{


	BinaryTree<char> bin;
	cout << "�����ַ���������������";
	bin.CreateBinTree();

	cout << "��������������ӦΪ��";
	bin.InOrder();
	cout << endl;

	cout << "��������������ӦΪ��";
	bin.PostOrder();
	cout << endl;

	cout << "��������������ӦΪ��" << bin.Height() << endl;
	cout << "�����������Ҷ����ĿӦΪ: " << bin.Leaf() << endl;
	
	bin.PerOrder();  //4��ջΪ�����洢�ṹʵ�ֶ�������ǰ��ǵݹ��㷨
	cout << endl;
	system("PAUSE");

	return 0;
}