#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = s;
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[pivot] > arr[i])
        {
            count++;
        }
    }
    pivot = s + count;
    cout << pivot << endl;
    swap(arr[pivot], arr[s]);

    int i = s, j = e;
    while (i < pivot && j > pivot)
    {
        while (arr[i] < arr[pivot])
        {
            i++;
        }
        while (arr[j] > arr[pivot])
        {
            j--;
        }
        if (i < pivot && j > pivot)
        {
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }
    cout << "hi" << endl;
    return pivot;
}

void quickSort(int arr[], int s, int e)
{
    // base condition
    if (s >= e)
        return;

    // Partition
    int p = partition(arr, s, e);

    // recurrence
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {3, 1, 4, 5, 2};
    print(arr, 5);
    quickSort(arr, 0, 4);
    print(arr, 5);
    return 0;
}