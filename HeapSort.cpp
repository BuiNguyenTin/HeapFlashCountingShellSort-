#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std;

// Heapify
void Heapify(int a[], int n, int i)
{
    int max = i;
    int l = i * 2 + 1;
    int r = l + 1;
    if (l<n && a[l] > a[max])
    {
        max = l;
    }

    if (r<n && a[r] > a[max])
    {
        max = r;
    }

    if (max != i)
    {
        swap(a[i], a[max]);
        Heapify(a, n, max);
    }

}

// Heapify with comparison
void ComparisonHeapify(int a[], int n, int i, int& comparison)
{
    int max = i;
    int l = i * 2 + 1;
    int r = l + 1;
    if ((++comparison && l < n) && (++comparison && a[l] > a[max]))
    {
        max = l;
    }

    if ((++comparison && r < n) && (++comparison && a[r] > a[max]))
    {
        max = r;
    }

    if (++comparison && max != i)
    {
        swap(a[i], a[max]);
        ComparisonHeapify(a, n, max, comparison);
    }
}

// Heap sort
void HeapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(a, n, i);

    for (int j = n - 1; j > 0; j--)
    {
        swap(a[0], a[j]);
        Heapify(a, j, 0);
    }
}

// Heap sort with comparison
void ComparisonHeapSort(int a[], int n, int& comparison)
{
    for (int i = n / 2 - 1; ++comparison && i >= 0; i--)
        ComparisonHeapify(a, n, i, comparison);

    for (int j = n - 1; ++comparison && j > 0; j--)
    {
        swap(a[0], a[j]);
        ComparisonHeapify(a, j, 0, comparison);
    }
}

// Runtime sort 
void RuntimeHeapSort(int a[], int n, double& time)
{
    auto start = chrono::steady_clock::now();
    HeapSort(a, n);
    auto endtime = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> diff = endtime - start;
    time = diff.count();
}