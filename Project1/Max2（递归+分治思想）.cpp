#include <iostream>
#include <algorithm>
using namespace std;

void max2(int a[], int lo, int hi, int& x1, int& x2) {
	if (lo + 2 == hi) {
		if (a[lo] >= a[hi - 1]) {
			x1 = a[lo];
			x2 = a[hi - 1];
			return;
		}
		else { x1 = a[hi - 1]; x2 = a[lo]; return; }
	}
	if (lo + 3 == hi) {
		x1 = max(a[lo], max(a[lo + 1], a[hi - 1]));
		x2 = a[lo] + a[lo + 1] + a[hi - 1] - x1 - min(a[lo], min(a[lo + 1], a[lo + 2]));
		return;
	}
	int mi = (lo + hi) >> 1;
	int x1L, x2L; max2(a, lo, mi, x1L, x2L);
	int x1R, x2R; max2(a, mi, hi, x1R, x2R);
	if (a[x1L] > a[x1R]) {
		x1 = x1L; x2 = (a[x2L] > a[x1R]) ? x2L : x1R;
		return;
	}
	else { x1 = x1R; x2 = (a[x1L] > a[x2R]) ? x1L : x2R; return; }
}
int main4()
{
	int a[10] = { 8, 3, 30, 25, 10, 22, 31, 35, 21, 19 };
	int x1 = 0, x2 = 0;
	max2(a, 0, 8, x1, x2);
	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;
	return 0;
}


/*void max2(int A[], int lo, int hi, int& x1, int& x2)
{
	if (lo + 2 == hi) {
		if (A[lo] >= A[hi - 1]) {
			x1 = A[lo];
			x2 = A[hi - 1];
			return;
		}
		else {
			x1 = A[hi - 1];
			x2 = A[lo];
			return;
		}
		return;
	}
	if (lo + 3 == hi) {
		x1 = max(A[lo], max(A[lo + 1], A[hi - 1]));
		x2 = A[lo] + A[lo + 1] + A[hi - 1] - x1 - min(A[lo], min(A[lo + 1], A[hi - 1]));

		return;
	}

	int mi = (lo + hi) / 2;
	int x1L, x2L;
	int x1R, x2R;

	max2(A, lo, mi, x1L, x2L);
	max2(A, mi, hi, x1R, x2R);

	if (A[x1L] > A[x1R]) {
		x1 = x1L;
		x2 = (A[x2L] > A[x1R]) ? x2L : x1R;
		return;
	}
	else {
		x1 = x1R;
		x2 = (A[x1L] > A[x2R]) ? x1L : x2R;
		return;
	}
}

int main()
{
	int a[10] = { 88, 3, 30, 25, 10, 38, 31, 35, 22, 19 };
	int x1 = 0, x2 = 0;

	max2(a, 0, 10, x1, x2);
	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;

	return 0;
}*/