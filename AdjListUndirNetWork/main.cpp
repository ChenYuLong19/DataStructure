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

	//����һ����󶥵���Ϊ10������6�����������ͼ��û�л��Ķ����Ȩ��Ϊ9999
	AdjListUndirGraph<int, int> UndirNetWork(a, 6, 10, 9999);
	UndirNetWork.InsertArc(1, 3, 1);  //��������Ϊ1��3��Ȩ��Ϊ1�Ļ�
	UndirNetWork.InsertArc(1, 4, 1);
	UndirNetWork.InsertArc(3, 4, 1);
	UndirNetWork.InsertArc(3, 6, 1);
	UndirNetWork.InsertArc(4, 6, 1);
	UndirNetWork.InsertArc(2, 5, 1);

	cout << "������ȱ�������ͼ�����Ϊ��" << endl;
	UndirNetWork.DFSTraverse();
	cout << endl;
	system("PAUSE");
	//ɾ�����㻹û��д
	return 0;
}
