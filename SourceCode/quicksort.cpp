#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

void quick_sort(int a[], int left, int right) {
    int i = left, j = right;
    int temp;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j) quick_sort(a, left, j);
    if (i < right) quick_sort(a, i, right);
}

int main()
{

    fstream f("test.txt", ios::in);
    int n = 1000000;
    int *a = (int *)calloc(1000000, sizeof(int));
    cout << "Quicksort"<<endl;
    int i;
    for ( i = 0; i < 10; i++)
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
        quick_sort(a, 0, 999999);
        end = clock();

        time_use = (double)(end - start) / CLOCKS_PER_SEC;
        cout << time_use;
        cout << "\n";
    }
    f.close();
    return 0;
}
