#include <iostream>
using namespace std;

void InsertionSort(int a[], int n)
{
	for (int j = 1; j < n; j++)
	{
		int key = a[j]; //�������һ��Ԫ��,Ĭ�������һ��Ԫ��Ϊ��������
		int i = j - 1;  //�����Ѿ��Ź����Ԫ�����һ��������
		while (i >= 0 && key < a[i])
		{
			//�Ӻ���ǰ����Ƚ��Ѿ���������飬�������С����Ѻ�����ǰ�ߴ��棬
			//��ʵ˵���˾�������������ƶ�һλ,Ϊ�ҵ����ʵ�λ��ʱ�����Key�Ĳ���
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;//�ҵ����ʵ�λ���ˣ���ֵ,��i�����ĺ�������keyֵ��
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