#include <iostream>
using namespace std;
#define ArraySize 8


void radix(int data[], int size)
{
	int n;
	for (int i = 1; i <= 100; i = i * 10)
	{
		int tmp[20][10] = { 0 };//����һ��20�У�10�е����飬ÿһ�зֱ����0~9λ����20�д����ܴ�ŵ��ܸ���
		for (int j = 0; j < size; j++)
		{
			n = (data[j] / i) % 10;
			tmp[j][n] = data[j];
		}
		int k = 0;
		for (int p = 0; p < 10; p++)
			for (int q = 0; q < size; q++)
			{
				if (tmp[q][p] != 0)
					data[k++] = tmp[q][p];
			}
	}
}


int main()
{
	int data[ArraySize];
	/*������������*/
	cout << "������8������" << endl;
	for (int i = 0; i < ArraySize; i++)
		cin >> data[i];
	/*ִ������*/
	radix(data, 8);
	/*���������*/
	cout << "" << endl;
	for (int i = 0; i < ArraySize; i++)
		cout << data[i] << " ";
	return 0;
}
