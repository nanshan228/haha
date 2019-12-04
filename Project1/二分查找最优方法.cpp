#include <iostream>
#include <vector>
using namespace std;

//有多个命中元素时，总能保证返回回秩最大者；查找失败时，能够返回失败的位置（把下标放入数组后即可判断是否失败）
int binarySearch(char* A, int e, int lo, int hi)
{
	int mi;
	while (lo < hi) {
		mi = (lo + hi)/2;
		(e < A[mi]) ? hi = mi : lo = mi + 1;
	}
	return --lo; //循环结束时，lo为大于e的元素的最小秩，故lo-1即为大于e的元素的最大秩
}

int main()
{
	char a[10] = { 0,1,2,3,4,5,6,7,7,9 };

	int sub = binarySearch(a, 55, 1, 10);
	cout << "所查找到的元素是" << sub << endl;

	return 0;
}