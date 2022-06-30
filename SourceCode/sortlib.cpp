#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

int partition(int a[], int left, int right)
{
    int pivot = a[right];
    int vt = left - 1;
    for (int i = left; i <= right - 1; i++)
    {
        if (a[i] < pivot)
        {
            vt++;
            swap(a[vt], a[i]);
        }
    }
    vt++;
    swap(a[vt], a[right]);
    return vt;
}
void quick_sort(int a[], int left, int right)
{
    if (left < right)
    {
        int pivot = partition(a, left, right);
        quick_sort(a, left, pivot - 1);
        quick_sort(a, pivot + 1, right);
    }
}

int main()
{

    fstream f("test.txt", ios::in);
    int n = 1000000;
    int *a = (int *)calloc(1000000, sizeof(int));
    cout << "Sortlib"<<endl;
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
        sort(a,a+1000000);
         end = clock();

         time_use = (double)(end - start) / CLOCKS_PER_SEC;
         cout << time_use;
        cout << "\n";
    }
    f.close();
    return 0;
}
