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
	bin.CreateBinTree();//先序建立二叉树

	cout << "输出中序遍历序列应为：";
	bin.InOrder(visit);
	cout << endl;

	cout << "输出后序遍历序列应为：";
	bin.PostOrder(visit);
	cout << endl;

	cout << "输出二叉树的深度应为：" << bin.Height() << endl;
	cout << "输出二叉树的叶子数目应为: " << bin.Leaf() << endl;
	system("PAUSE");

	return 0;
}