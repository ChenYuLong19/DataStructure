/*
交换排序：冒泡排序(稳定)，快速排序(不稳定)
插入排序：直接插入排序(稳定)，折半插入排序(稳定)，希尔排序(不稳定)
选择排序：简单选择排序(不稳定)，锦标赛排序，堆排序(不稳定）
归并排序：两路归并排序(稳定)，递归归并排序
基数排序：多关键字排序，链式基数排序
*/
#include<iostream>
using namespace std;
template<class ElemType>
void QuickSort(ElemType elem[], int low, int high) /*快速排序*/
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
	elem[i] = e;  //到这里i和j是相等的
	if (low < i - 1) QuickSort(elem, low, i - 1);
	if (high > j + 1)QuickSort(elem, j + 1, high);
}


template<class ElemType>
void StraightInsertSort(ElemType elem[], int n) /*直接插入排序*/
{
	for (int i = 1; i < n; i++)
	{
		ElemType temp = elem[i];
		int j;
		for (j = i - 1; j >= 0 && temp < elem[j]; j--) //j=i更方便
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