#include <iostream>
#include <vector>

using namespace std;

void merge(int a[], int l, int m, int r) {
	int n1 = m - l + 1, n2 = r - m;
	vector<int>x1(n1);
	vector<int>x2(n2);
	for (int i = l; i <= m; i++) x1[i - l] = a[i];
	for (int i = m + 1; i <= r; i++) x2[i - m - 1] = a[i];
	int i = 0, j = 0, t = l;
	while (i < n1 && j < n2) {
		if (x1[i] <= x2[j]) a[t++] = x1[i++];
		else a[t++] = x2[j++];
	}
	while (i < n1) a[t++] = x1[i++];
	while (j < n2) a[t++] = x2[j++];
}

void Merge_sort(int a[], int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		Merge_sort(a, l, m);
		Merge_sort(a, m + 1, r);
		merge(a, l, m, r);
	}
}