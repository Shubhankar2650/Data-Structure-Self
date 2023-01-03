#include <bits/stdc++.h.txt>
using namespace std;

class MinHeap
{
public:
    int *arr;
    int size;
    int capacity;

    MinHeap(int c)
    {
        arr = new int(c);
        size = 0;
        capacity = c;
    }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    int parent(int i) { return ((i - 1) / 2); }

    void insert(int a)
    {
        if (size > capacity)
            return;

        size++;
        arr[size - 1] = a;
        int x = size - 1;

        for (int i = size - 1; i != 0 && arr[parent(i)] > arr[i];)
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
        // while (x != 0)
        // {
        //     if (arr[x] > arr[parent(x)])
        //     {
        //         swap(arr[x], arr[parent(x)]);
        //         x = parent(x);
        //     }
        //     else
        //         return;
        // }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << ",";
        }
    }
};

int main()
{
    MinHeap m(10);
    m.insert(5);
    m.insert(23);
    m.insert(12);
    m.insert(34);
    m.insert(11);
    m.print();
}