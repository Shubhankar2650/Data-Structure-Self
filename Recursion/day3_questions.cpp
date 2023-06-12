#include <iostream>
using namespace std;

bool isSorted(int *arr, int n)
{
    if (n == 1 || n == 0)
        return true;

    if (arr[0] > arr[1])
        return false;
    else
    {
        return isSorted(arr + 1, n - 1);
    }
}

// for sum of the array
int sum(int *arr, int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];

    int total = arr[0] + sum(arr + 1, n - 1);
    return total;
}

// Linear search using recursion
bool searchLinear(int *arr, int n, int key)
{
    if (n == 0)
        return false;
    if (arr[0] == key)
        return true;
    else
    {
        bool temp = searchLinear(arr + 1, n - 1, key);
        return temp;
    }
}

// Binary Search

bool binarySearch(int *arr, int s, int e, int key)
{
    if (s > e)
    {
        return false;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == key)
    {
        cout << "The palce at which key is present is: " << mid << endl;
        return true;
    }

    if (arr[mid] > key)
    {
        binarySearch(arr, s, mid - 1, key);
    }
    else
    {
        binarySearch(arr, mid + 1, e, key);
    }
}

int main()
{
    int arr[] = {2, 4, 6, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    // bool ans = isSorted(arr, size);
    // int ans = sum(arr, size);
    // cout <<"sum is: " << ans;

    // cout << searchLinear(arr, size, 10);
    binarySearch(arr, 0, size - 1, 9);
    return 0;
}