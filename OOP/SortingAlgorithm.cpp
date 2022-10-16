#include<iostream>
#include<algorithm>
#include<random>
#include<vector>
#include<fstream>
#include<chrono>
#include<sstream>
#include<cstdlib>
#include"sort.h"
#define element 1000000
using namespace std;
using namespace std::chrono;
//Quick sort implementation
void quickSort(double arr[], int start, int end)
{
    if (start < end) {
        srand(time(NULL));
        int random = start + rand() % (end - start);
        swap(arr[random], arr[end]);
        double randvalue = arr[end];
        int i = (start - 1);

        for (int j = start; j <= end - 1; j++)
        {
            if (arr[j] <= randvalue) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[end]);
        quickSort(arr, start, i);
        quickSort(arr, i + 2, end);
    }
}
//Merge sort implementation

void mergeSort(double arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        int n1 = m - l + 1;
        int n2 = r - m;
        vector<double> left(n1), right(n2);
        for (int i = 0; i < n1; i++)
            left[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            right[j] = arr[m + 1 + j];
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2)
        {
            if (left[i] <= right[j])
            {
                arr[k] = left[i];
                i++;
            }
            else
            {
                arr[k] = right[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
}
// Heapsort implementation
void reorder(double arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        reorder(arr, n, largest);
    }
}
void heapSort(double arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        reorder(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        reorder(arr, i, 0);
    }
}
//
void stdSort(double arr[]) {
    sort(arr, arr + element);
}
//check whether arr is sort or not
bool isSort(double arr[]) {
    for (int i = 0; i < element - 1; i++) {
        if (arr[i] > arr[i + 1]) { return false; }
    }
    return true;
}