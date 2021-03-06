#include <iostream>
using namespace std;

void InsertionSort(int a[], int n)
{
	for (int j = 1; j < n; j++)
	{
		int key = a[j]; //待排序第一个元素,默认数组第一个元素为有序序列
		int i = j - 1;  //代表已经排过序的元素最后一个索引数
		while (i >= 0 && key < a[i])
		{
			//从后向前逐个比较已经排序过数组，如果比它小，则把后者用前者代替，
			//其实说白了就是数组逐个后移动一位,为找到合适的位置时候便于Key的插入
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;//找到合适的位置了，赋值,在i索引的后面设置key值。
	}
	for (int h=0;h<n;h++)
	{
		cout << a[h] << endl;
	}
}
void main()
{
	int a[8] = { 1,2,32,5,7,21,34,27 };
	InsertionSort(a, 8);
}