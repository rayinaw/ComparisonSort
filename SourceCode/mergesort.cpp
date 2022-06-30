#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

void merge(int a[], int left, int mid, int right)
{
    int *temp = new int[right - left + 1];
    int m;
    int i = left;
    int j = mid + 1;
    m = 0;
    while (!(i > mid && j > right))
    {
        if ((i <= mid && j <= right && a[i] < a[j]) || j > right)
            temp[m++] = a[i++];
        else
            temp[m++] = a[j++];
    }
    for (i = 0; i < m; i++)
        a[left + i] = temp[i];
    delete temp;
}

void merge_sort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main()
{

    fstream f("test.txt", ios::in);
    int n = 1000000;
    int *a = (int *)calloc(1000000, sizeof(int));
    cout << "Mergesort"<<endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < n; j++)
        {
            f >> a[j];
        }
        cout << "test " << i + 1 << ": ";
        cout << "\t" << "\t";
        clock_t start, end;
        double time_use;
        start = clock();
        merge_sort(a, 0, 999999);
        end = clock();
        time_use = (double)(end - start) / CLOCKS_PER_SEC;
        cout << time_use;
        cout << "\n";
    }
    f.close();
    return 0;
}
