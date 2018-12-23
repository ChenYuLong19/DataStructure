/*
��������ð������(�ȶ�)����������(���ȶ�)
��������ֱ�Ӳ�������(�ȶ�)���۰��������(�ȶ�)��ϣ������(���ȶ�)
ѡ�����򣺼�ѡ������(���ȶ�)�����������򣬶�����(���ȶ���
�鲢������·�鲢����(�ȶ�)���ݹ�鲢����
�������򣺶�ؼ���������ʽ��������
*/
#include<iostream>
using namespace std;
template<class ElemType>
void QuickSort(ElemType elem[], int low, int high) /*��������*/
{
	ElemType e = elem[low];
	int i = low, j = high;
	while (i < j)
	{
		while (i < j&&elem[j] >= e) j--;
		if (i < j) elem[i++] = elem[j];
		while (i < j&&elem[i] <= e) i++;
		if (i < j) elem[j--] = elem[i];
	}
	elem[i] = e;  //������i��j����ȵ�
	if (low < i - 1) QuickSort(elem, low, i - 1);
	if (high > j + 1)QuickSort(elem, j + 1, high);
}


template<class ElemType>
void StraightInsertSort(ElemType elem[], int n) /*ֱ�Ӳ�������*/
{
	for (int i = 1; i < n; i++)
	{
		ElemType temp = elem[i];
		int j;
		for (j = i - 1; j >= 0 && temp < elem[j]; j--) //j=i������
			elem[j + 1] = elem[j];
		elem[j + 1] = temp;
	}
}

int main()
{
	int arry[20] = { 49,38,65,97,76,13,49,27 };
	StraightInsertSort(arry, 8);
	for (int i = 0; i < 8; i++)
		cout << arry[i] << ' ';
	cout << endl;
	system("pause");
	QuickSort(arry, 0, 7);
	for (int i = 0; i <= 7; i++)
		cout << arry[i] << ' ';
	cout << endl;
	system("pause");
	return 0;
}