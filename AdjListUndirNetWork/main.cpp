#include"AdjListUndirGraph.cpp"
#include<iostream>
using namespace std;
int main()
{
	string a[6] = { "v1","v2","v3","v4","v5","v6", };

	/*AdjListUndirGraph<int, int> UdNW(a,5,10,9999);
	UdNW.InsertArc(2, 3, 1);
	system("PAUSE");
	try {
		UdNW.FirstAdjVex(0);
	}
	catch(const string str){
		cout << str << endl;
	}
	system("PAUSE");*/

	//创建一个最大顶点数为10，含有6个顶点的无向图，没有弧的顶点间权重为9999
	AdjListUndirGraph<string, int> UndirGraph(a, 6, 10, 9999);
	UndirGraph.InsertArc(1, 3, 1);  //建立顶点为1和3的权重为1的弧
	UndirGraph.InsertArc(1, 4, 1);
	UndirGraph.InsertArc(3, 4, 1);
	UndirGraph.InsertArc(3, 6, 1);
	UndirGraph.InsertArc(4, 6, 1);
	UndirGraph.InsertArc(2, 5, 1);

	cout << "深度优先遍历无向图的输出为：" << endl;
	UndirGraph.DFSTraverse();
	cout << endl;
	system("PAUSE");
	//删除顶点还没有写
	return 0;
}
