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
	system("PAUSE");

	return 0;
}