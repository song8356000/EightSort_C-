
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*�ú����������±귶Χ[l1,r1]��[l2,r2]���������кϲ���һ����������*/
void merge(vector<int>& nums, int l1, int r1, int l2, int r2) {
	int i = l1;                                               //��벿����ʼλ��
	int j = l2;                                               //�Ұ벿����ʼλ��
	int n = (r1 - l1 + 1) + (r2 - l2 + 1);                    //Ҫ�ϲ���Ԫ�ظ���
	vector<int> temp(n);                                      //��������
	int k = 0;	                                          //������������ʼλ��
	while (i <= r1&&j <= r2) {                                //��ѡ����������С��Ԫ�ط��븨��������
		if (nums[i] < nums[j])
			temp[k++] = nums[i++];
		else
			temp[k++] = nums[j++];
	}
	//�������ʣ�ֱ࣬�ӷ��뵽����������
	while (i <= r1)
		temp[k++] = nums[i++];
	while (j <= r2)
		temp[k++] = nums[j++];
	//����ԭʼ����Ԫ��
	for (int i = 0; i < n; i++)
	{
		nums[l1 + i] = temp[i];
	}
}

/*��·�鲢���򣨵ݹ�ʵ�֣�*/
void MergeSort(vector<int>& nums, int start, int end) {
	if (start < end) {
		int mid = (start + end) >> 1;				//�ָ�����
		MergeSort(nums, start, mid);				//��������벿�ֽ��й沢����
		MergeSort(nums, mid + 1, end);				//�������Ұ벿�ֽ��й沢����
		merge(nums, start, mid, mid + 1, end);                  //�ϲ��Ѿ��������������
	}
}

/*��·�鲢���򣨵���ʵ�֣�*/
void MergeSort1(vector<int>& nums, int start, int end)
{
	int n = nums.size();
	if (start < end) {
		//stepΪ����Ԫ�ظ�����step/2Ϊ��������Ԫ�ظ���
		for (int step = 2; step / 2 < n; step *= 2) {
			//ÿstep��Ԫ��һ�飬����ǰstep/2�ͺ�step/2��Ԫ�ؽ��кϲ�
			for (int i = 0; i < n; i += step) {
				int mid = i + step / 2 - 1;					//��������Ԫ�ظ���Ϊstep/2
				if (mid + 1 < n)							//�����������Ԫ�ظ�����ϲ�
														//��������Ϊ[i,mid]����������Ϊ[mid+1, min(i+step-1, n-1)]
					merge(nums, i, mid, mid + 1, min(i + step - 1, n - 1));
			}
		}
	}
}

int main() {
	vector<int> nums{ 1,4,3,2,5,6,3 };
	MergeSort(nums, 0, 6);
	//	MergeSort1(nums, 0, 6);
	for (auto x : nums)
		cout << x << " ";
	cout << endl;
	return 0;
}