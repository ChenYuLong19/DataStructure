#include<iostream>
#include<stdio.h>
using namespace std;
template<class ElemType>
void QuickSort(ElemType elem[], int low, int high)
{
	static int count=0;
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
	if (count % 2 == 0)
	{
		for (int k = 0; k <= 7; k++)
		cout << elem[k] << ' ';
		cout << endl;

	}
	count++;
	if (low < i - 1) QuickSort(elem, low, i - 1);
	if (high > j + 1)QuickSort(elem, j + 1, high);
}
int main()
{
	int arry[20] = { 49,38,65,97,76,13,49,27 };
	QuickSort(arry, 0, 7);
	for (int i = 0; i <= 7; i++)
		cout << arry[i] << ' ';
	cout << endl;
	system("pause");
	return 0;
}