#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

void heap(int a[], int n, int parent)
{
    int largest=parent;
    int i = parent * 2 + 1;
    int j = parent * 2 + 2;
    if (i < n && a[i] > a[largest])
        largest = i;
    if (j < n && a[j] > a[largest])
        largest = j;
    if (largest != parent){
        swap(a[parent], a[largest]);
        heap(a, n, largest);
    }
}

void heapsort(int a[], int n)
{
    int parent = n / 2 - 1;
    while (parent >= 0)
    {
        heap(a, n, parent);
        parent--;
    }
    int i = n - 1;
    for (int i = n - 1; i > 0; i--){
        swap(a[0], a[i]);
        heap(a, i, 0);
    }
}

int main()
{

    fstream f("test.txt", ios::in);
    int n = 1000000;
    int *a = (int *)calloc(1000000, sizeof(int));
    cout << "Heapsort" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < n; j++)
        {
            f >> a[j];
        }
        cout << "test " << i + 1 << ": ";
        cout << "\t"
             << "\t";
        clock_t start, end;
        double time_use;
        start = clock();
        heapsort(a, n);
        end = clock();
        time_use = (double)(end - start) / CLOCKS_PER_SEC;
        cout << time_use;
        cout << "\n";
    }
    f.close();
    return 0;
}
