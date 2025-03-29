#include <iostream>
#include <climits>
using namespace std;
using ll = long long; 

void Counting_sort(int a[], int n) {
	int min = INT_MAX, max = INT_MIN; 
	for (int i = 0; i < n; i++) {
		if (a[i] > max) max = a[i]; 
		if (a[i] < min) min = a[i]; 
	}
	int bound = max - min + 1; 
	int* mark = new int[bound](); 
	for (int i = 0; i < n; i++) {
		mark[a[i] - min]++; 
	}
	int idx = 0;
	for (int i = 0; i < bound; i++) {
		while (mark[i]--) {
			a[idx++] = i + min;
		}
	}
	delete[] mark; 
}

void printarray(int a[], int n) {
	Counting_sort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}