#include <iostream>
#include <algorithm>

using namespace std;

void insertion_sort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int x = a[i], pos = i - 1; 
		while (pos >= 0 && a[pos] > x) {
			a[pos + 1] = a[pos]; 
			pos--; 
		}
		a[pos + 1] = x; 
	}
}
