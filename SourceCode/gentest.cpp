#include <bits/stdc++.h>
using namespace std;

void reverse(int *a, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        swap(a[i], a[n - 1 - i]);
    }
}

void ascending(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = (rand() * rand()) % 10000000;
    }
    sort(a,a+1000000);
}

void decending(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = (rand() * rand()) % 10000000;
    }
    sort(a,a+1000000);
    reverse(a, n);
}

void random(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = (rand() * rand()) % 10000000;
    }
}

int main()
{
    srand(int(time(0)));
    int n = 1000000;
    int *a = new int[n];
    ofstream f;
    f.open("test.txt");
    ascending(a, n);
    for (int i = 0; i < n; i++)
    {
        f << a[i] << " ";
    }
    decending(a, n);
    for (int i = 0; i < n; i++)
    {
        f << a[i] << " ";
    }
    for (int i = 1; i <= 8; i++)
    {
        random(a, n);
        for (int j = 0; j < n; j++)
        {
            f << a[j] << " ";
        }
    }
    f.close();
    delete a;

    return 0;
}
