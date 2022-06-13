#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std;

// Shell sort
void ShellSort(int a[], int n)
{
    for (int interval = n / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < n; i += 1)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
            {
                a[j] = a[j - interval];
            }
            a[j] = temp;
        }
    }
}

// Shell sort with comparison
void ComparisonShellSort(int a[], int n, int& comparison)
{
    for (int interval = n / 2; ++comparison && interval > 0; interval /= 2)
    {
        for (int i = interval; ++comparison && i < n; i += 1)
        {
            int temp = a[i];
            int j;
            for (j = i; (++comparison && j >= interval) && (++comparison && a[j - interval] > temp); j -= interval)
            {
                a[j] = a[j - interval];
            }
            a[j] = temp;
        }
    }
}

// Runtime sort 
void RuntimeShellSort(int a[], int n, double& time)
{
    auto start = chrono::steady_clock::now();
    ShellSort(a, n);
    auto endtime = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> diff = endtime - start;
    time = diff.count();
}