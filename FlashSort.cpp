#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std;

template <class T>
void HoanVi(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}

// Insertion sort
void InsertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while (a[k] > key && k >= 0)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}

// Insertion sort with comparison
void ComparisonInsertionSort(int a[], int n, int& comparison)
{
	for (int i = 1; ++comparison && i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while ((++comparison && a[k] > key) && (++comparison && k >= 0))
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}

// Flash sort
void FlashSort(int a[], int n)
{
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	HoanVi(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	InsertionSort(a, n);
}

// Flash sort with comparison
void ComparisonFlashSort(int a[], int n, int& comparison)
{
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; ++comparison && i < m; i++)
		l[i] = 0;
	for (int i = 1; ++comparison && i < n; i++)
	{
		if (++comparison && a[i] < minVal)
			minVal = a[i];
		if (++comparison && a[i] > a[max])
			max = i;
	}
	if (++comparison && a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; ++comparison && i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; ++comparison && i < m; i++)
		l[i] += l[i - 1];
	HoanVi(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (++comparison && nmove < n - 1)
	{
		while (++comparison && j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (++comparison && k < 0) break;
		while (++comparison && j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	ComparisonInsertionSort(a, n, comparison);
}

// Runtime sort 
void RuntimeFlashSort(int a[], int n, double& time)
{
	auto start = chrono::steady_clock::now();
	FlashSort(a, n);
	auto endtime = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::milli> diff = endtime - start;
	time = diff.count();
}