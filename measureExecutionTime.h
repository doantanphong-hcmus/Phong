#pragma once
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

void printList(int* arr, int n);
void makeCopyArr(int*& arr1, int*& arr2, int n);
void destroy(int*& arr);
int* generateRandomArray(int size, int min, int max);
int* generateSortedArray(int size, int min, int max);
int* generateReversedArray(int size, int min, int max);
int* generateNearlySortedArray(int size, int min, int max);

template <typename Func, typename... Args>
double measureExecutionTime(Func func, Args &&...args) {
    auto start = std::chrono::high_resolution_clock::now();
    func(std::forward<Args>(args)...);

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    return duration.count() / 1000.0;
}