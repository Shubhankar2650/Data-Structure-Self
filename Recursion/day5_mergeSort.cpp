#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    int l = mid - s + 1; // left array  length
    int r = e - mid;     // right array length

    int *arr1 = new int[l];
    int *arr2 = new int[r];

    int k = s;
    for (int i = 0; i < l; i++)
    {
        arr1[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < r; i++)
    {
        arr2[i] = arr[k++];
    }

    int i = 0, j = 0;
    k = s;
    while (i < l && j < r)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }

    while (i < l)
    {
        arr[k] = arr1[i];
        k++;
        i++;
    }
    while (j < r)
    {
        arr[k] = arr2[j];
        k++;
        j++;
    }
}

void mergeSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    // copy left side of mid in a array
    mergeSort(arr, s, mid);
    // copy right side of mid in the array
    mergeSort(arr, mid + 1, e);

    // merge
    merge(arr, s, e);
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
    }
}

int main()
{
    int arr[] = {4, 2, 6, 4, 8};
    print(arr, 5);
    mergeSort(arr, 0, 4);
    cout << endl;
    print(arr, 5);
    return 0;
}