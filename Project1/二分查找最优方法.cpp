#include <iostream>
#include <vector>
using namespace std;

//�ж������Ԫ��ʱ�����ܱ�֤���ػ�������ߣ�����ʧ��ʱ���ܹ�����ʧ�ܵ�λ�ã����±��������󼴿��ж��Ƿ�ʧ�ܣ�
int binarySearch(char* A, int e, int lo, int hi)
{
	int mi;
	while (lo < hi) {
		mi = (lo + hi)/2;
		(e < A[mi]) ? hi = mi : lo = mi + 1;
	}
	return --lo; //ѭ������ʱ��loΪ����e��Ԫ�ص���С�ȣ���lo-1��Ϊ����e��Ԫ�ص������
}

int main()
{
	char a[10] = { 0,1,2,3,4,5,6,7,7,9 };

	int sub = binarySearch(a, 55, 1, 10);
	cout << "�����ҵ���Ԫ����" << sub << endl;

	return 0;
}