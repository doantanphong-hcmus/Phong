#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;


// Print Array.
void printList(int* arr, int n)
{
    // Arr là m?ng s? d?ng con tr?, n là s? l??ng ph?n t?
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function copy arr1 to arr2 with size n.
// Copy t? arr1 qua arr2 ?? ti?n sort.
void makeCopyArr(int*& arr1, int*& arr2, int n)
{
    if (arr1 == NULL) return;
    arr2 = new int[n];
    for (int i = 0; i < n; i++)  arr2[i] = arr1[i];
}

// Function destroy pointer array.
// Dùng ?? delete m?ng con tr?.
void destroy(int*& arr) {
    if (arr == NULL)   return;
    delete[] arr;
}

// T?o ra m?t m?ng v?i size và kho?ng t? min ??n max.
// Function to generate a random array.
int* generateRandomArray(int size, int min, int max) {
    if (size == 0) return NULL;
    int* arr = new int[size];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);

    for (int i = 0; i < size; i++) {
        arr[i] = distrib(gen);
    }

    return arr;
}

// Function to generate a sorted array.
int* generateSortedArray(int size, int min, int max) {
    if (size == 0) return NULL;
    int* arr = generateRandomArray(size, min, max);

    sort(arr, arr + size);

    return arr;
}

// Function to generate a reversed array.
int* generateReversedArray(int size, int min, int max) {
    if (size == 0) return NULL;
    int* arr = generateRandomArray(size, min, max);

    sort(arr, arr + size);
    reverse(arr, arr + size);

    return arr;
}

// Function to generate an array where 80% of it is sorted.
int* generateNearlySortedArray(int size, int min, int max) {
    if (size == 0) return NULL;
    int* arr = generateRandomArray(size, min, max);

    int sizeSorted = size * 8 / 10;
    int sizeUnSorted = size - sizeSorted;

    srand(time(0));  // Seed ?? sinh s? ng?u nhiên m?i l?n ch?y
    int randomNumber = rand() % (sizeUnSorted + 1);  // S? ng?u nhiên t? 0 ??n v? trí c?n ?c sort

    sort(arr + randomNumber, arr + randomNumber + sizeSorted);

    return arr;
}

// Hàm ??m th?i gian ch?y.
// s? d?ng thì b?n call: double time = measureExecutionTime(<yourSortFunction>, <yourArrTmp>, n);
template <typename Func, typename... Args>
double measureExecutionTime(Func func, Args &&...args) {
    auto start = std::chrono::high_resolution_clock::now();
    func(std::forward<Args>(args)...);

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    return duration.count() / 1000.0;
}
