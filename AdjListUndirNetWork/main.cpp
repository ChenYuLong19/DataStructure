#include"AdjListUndirGraph.cpp"
#include"AdjListUndirGraph.h"
#include<iostream>
using namespace std;
int main()
{
	int a[6] = { 1,2,3,4,5,6 };

	/*AdjListUndirGraph<int, int> UdNW(a,5,10,9999);
	UdNW.InsertArc(2, 3, 1);
	cout << UdNW.GetElem(1) << endl;

	system("PAUSE");
	try {
		UdNW.FirstAdjVex(-1);
	}
	catch(const string str){
		cout << str << endl;
	}
	system("PAUSE");
	cerr << UdNW.FirstAdjVex(2) << endl;
	system("PAUSE");*/

	//创建一个最大顶点数为10，含有6个顶点的无向图，没有弧的顶点间权重为9999
	AdjListUndirGraph<int, int> UndirNetWork(a, 6, 10, 9999);
	UndirNetWork.InsertArc(1, 3, 1);  //建立顶点为1和3的权重为1的弧
	UndirNetWork.InsertArc(1, 4, 1);
	UndirNetWork.InsertArc(3, 4, 1);
	UndirNetWork.InsertArc(3, 6, 1);
	UndirNetWork.InsertArc(4, 6, 1);
	UndirNetWork.InsertArc(2, 5, 1);

	cout << "深度优先遍历无向图的输出为：" << endl;
	UndirNetWork.DFSTraverse();
	cout << endl;
	system("PAUSE");
	//删除顶点还没有写
	return 0;
}
