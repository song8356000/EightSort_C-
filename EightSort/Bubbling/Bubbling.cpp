#include <iostream>
using namespace std;

void bubblingsort(int a[], int n) //n�ǳ�Ա��
{
	for (int i=0;i<n-1;i++)              //ð������
	{
		for (int j=0;j<n-i-1;j++)
		{
			if (a[j]>a[j+1])
			{
				int one;
				one = a[j];
				a[j] = a[j+1];
				a[j+1] = one;
			}
		}
	}
	for (int i=0;i<n;i++)    //������кõ������Ա
	{
		//printf("%d\n", a[i]);
		cout << a[i] << endl;
	}
}
void main()
{
	int a[8] = { 0,11,2,32,42,5,6,121 };
	bubblingsort(a, 8);
	getchar();
}
