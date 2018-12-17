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
	
	bin.PerOrder();  //4以栈为辅助存储结构实现二叉树的前序非递归算法
	cout << endl;
	system("PAUSE");

	return 0;
}