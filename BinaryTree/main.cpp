#include<iostream>
#include"BinaryTree.cpp"
using namespace std;
int  main()
{


	BinaryTree<char> bin;
	cout << "输入字符串建立二叉树：";
	bin.CreateBinTree();

	cout << "输出中序遍历序列应为：";
	bin.InOrder();
	cout << endl;

	cout << "输出后序遍历序列应为：";
	bin.PostOrder();
	cout << endl;

	cout << "输出二叉树的深度应为：" << bin.Height() << endl;
	cout << "输出二叉树的叶子数目应为: " << bin.Leaf() << endl;
	system("PAUSE");

	return 0;
}