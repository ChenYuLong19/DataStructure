#include<iostream>
#include"BinaryTree.cpp"
using namespace std;
template<class ElemType>
void visit(const ElemType &e)
{
	cout << e;
}
int  main()
{


	BinaryTree<char> bin;
	bin.CreateBinTree();//������������

	cout << "��������������ӦΪ��";
	bin.InOrder(visit);
	cout << endl;

	cout << "��������������ӦΪ��";
	bin.PostOrder(visit);
	cout << endl;

	cout << "��������������ӦΪ��" << bin.Height() << endl;
	cout << "�����������Ҷ����ĿӦΪ: " << bin.Leaf() << endl;
	system("PAUSE");

	return 0;
}