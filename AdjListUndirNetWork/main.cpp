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

	//����һ����󶥵���Ϊ10������6�����������ͼ��û�л��Ķ����Ȩ��Ϊ9999
	AdjListUndirGraph<string, int> UndirGraph(a, 6, 10, 9999);
	UndirGraph.InsertArc(1, 3, 1);  //��������Ϊ1��3��Ȩ��Ϊ1�Ļ�
	UndirGraph.InsertArc(1, 4, 1);
	UndirGraph.InsertArc(3, 4, 1);
	UndirGraph.InsertArc(3, 6, 1);
	UndirGraph.InsertArc(4, 6, 1);
	UndirGraph.InsertArc(2, 5, 1);

	cout << "������ȱ�������ͼ�����Ϊ��" << endl;
	UndirGraph.DFSTraverse();
	cout << endl;
	system("PAUSE");
	//ɾ�����㻹û��д
	return 0;
}
