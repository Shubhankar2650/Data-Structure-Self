#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(int *arr, int s, int e)
{
    if (s == e)
    {
        printArray(arr, e);
        return;
    }
    int i;
    for (i = s; i <= e; i++)
    {
        swap((arr + i), (arr + s));
        permutation(arr, s + 1, e);
        swap((arr + i), (arr + s));
    }
}

int main()
{
    return 0;
    int arr[] = {1, 2, 3};
    permutation(arr, 0, 2);
}