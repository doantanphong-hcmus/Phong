#include "Phong.h"
#include "measureExecutionTime.h"

using namespace std;

int main() {
    // Demo generate array
    int n = 10000;
    int* arr = generateRandomArray(n, 0, 10000);
    int* tmp = nullptr;
    // Demo make copy
    makeCopyArr(arr, tmp, n);
    printList(tmp, n);
    // Demo measure time
    double TakeSortTime = measureExecutionTime(selection_sort, tmp, 0, n - 1);
    cout << "Algorithm sort took " << TakeSortTime << " milliseconds" << std::endl;
    //printList(tmp, n);
    // Destroy pointer
    destroy(arr);
    destroy(tmp);
    return 0;
}