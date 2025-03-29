#include <iostream>
#include <algorithm>

using namespace std;

void selection_sort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_index = i; 
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[i]) min_index = j; 
		}
		swap(a[min_index], a[i]); 
	}
}

