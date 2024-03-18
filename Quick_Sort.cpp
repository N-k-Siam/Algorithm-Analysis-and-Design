#include <bits/stdc++.h>
using namespace std;

int part(int a[], int start, int end)
{
    int piv = a[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (a[j] < piv)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[end]);
    return i + 1;
}

void quick_Sort(int a[], int start, int end)
{
    if (start >= end)
        return;
    int p = part(a, start, end);
    quick_Sort(a, start, p - 1);
    quick_Sort(a, p + 1, end);
}

int main()
{
    int n, Search;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> Search;
    quick_Sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}