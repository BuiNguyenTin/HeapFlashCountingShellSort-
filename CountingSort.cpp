#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std;

// Count sort
void CountingSort(int a[], int n)
{

    int* output = new int[(const int)n + 1];
    int max = a[0];
    int min = a[0];

    int i;
    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
        else if (a[i] < min)
            min = a[i];
    }

    int k = max - min + 1;

    int* count_array = new int[(const int)k];
    for (i = 0; i < k; i++)
        count_array[i] = 0;

    for (i = 0; i < n; i++)
        count_array[a[i] - min]++;

    for (i = 1; i < k; i++)
        count_array[i] += count_array[i - 1];


    for (i = 0; i < n; i++)
    {
        output[count_array[a[i] - min] - 1] = a[i];
        count_array[a[i] - min]--;
    }

    for (i = 0; i < n; i++)
        a[i] = output[i];

    delete[] output;
    delete[] count_array;
}

// Count sort with comparison
void ComparisonCountingSort(int a[], int n, int& comparison)
{

    int* output = new int[(const int)n + 1];
    int max = a[0];
    int min = a[0];

    int i;
    for (i = 1; ++comparison && i < n; i++)
    {
        if (++comparison && a[i] > max)
            max = a[i];
        else if (++comparison && a[i] < min)
            min = a[i];
    }

    int k = max - min + 1;

    int* count_array = new int[(const int)k];
    for (i = 0; ++comparison && i < k; i++)
        count_array[i] = 0;

    for (i = 0; ++comparison && i < n; i++)
        count_array[a[i] - min]++;

    for (i = 1; ++comparison && i < k; i++)
        count_array[i] += count_array[i - 1];

    for (i = 0; ++comparison && i < n; i++)
    {
        output[count_array[a[i] - min] - 1] = a[i];
        count_array[a[i] - min]--;
    }

    for (i = 0; ++comparison && i < n; i++)
        a[i] = output[i];

    delete[] output;
    delete[] count_array;
}

// Runtime sort 
void RuntimeCountingSort(int a[], int n, double& time)
{
    auto start = chrono::steady_clock::now();
    CountingSort(a, n);
    auto endtime = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> diff = endtime - start;
    time = diff.count();
}