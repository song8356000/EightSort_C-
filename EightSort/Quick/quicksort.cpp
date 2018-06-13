#include <iostream>
using namespace std;

void print(int a[], int n) {
	for (int j = 0; j < n; j++) {
		cout << a[j] << "  ";
	}
	cout << endl;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int a[], int low, int high)
{
	int privotKey = a[low];                             //��׼Ԫ��  
	while (low < high) {                                   //�ӱ�����˽�������м�ɨ��  
		while (low < high  && a[high] >= privotKey) --high;  //��high ��ָλ����ǰ���������ൽlow+1 λ�á����Ȼ�׼Ԫ��С�Ľ������Ͷ�  
		swap(&a[low], &a[high]);
		while (low < high  && a[low] <= privotKey) ++low;
		swap(&a[low], &a[high]);
	}
	print(a, 10);
	return low;
}


void quickSort(int a[], int low, int high) {
	if (low < high) {
		int privotLoc = partition(a, low, high);  //����һ��Ϊ��  
		quickSort(a, low, privotLoc - 1);          //�ݹ�Ե��ӱ�ݹ�����  
		quickSort(a, privotLoc + 1, high);        //�ݹ�Ը��ӱ�ݹ�����  
	}
}

int main() {
	int a[10] = { 3,1,5,7,2,4,9,6,10,8 };
	cout << "��ʼֵ��";
	print(a, 10);
	quickSort(a, 0, 9);
	cout << "�����";
	print(a, 10);

}