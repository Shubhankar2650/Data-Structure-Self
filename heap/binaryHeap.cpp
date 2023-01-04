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

    void minHeapify(int i)
    {
        if (i >= size)
            return;
        int l = left(i), r = right(i);
        int smallest = i;
        if (l < size && arr[i] > arr[l])
        {
            smallest = l;
        }
        if (r < size && arr[i] > arr[r])
        {
            smallest = r;
        }
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    // Time complexity - 0(logn);

    // ✍️ extractmin()

    void rearrange(int i)
    {
        int l = left(i), r = right(i);
        int smallest = i;
        if (l < size && r < size && arr[l] < arr[r])
        {
            swap(arr[l], arr[i]);
            rearrange(l);
        }
        else if (l < size && r < size && arr[l] > arr[r])
        {
            swap(arr[r], arr[i]);
            rearrange(r);
        }
        else if (l < size)
        {
            swap(arr[l], arr[i]);
            rearrange(l);
        }
        else if (r < size)
        {
            swap(arr[r], arr[i]);
            rearrange(r);
        }
    }

    int extractMin()
    {
        int temp = arr[0];
        int i = 0;
        rearrange(i);
        size--;
        return temp;
    }

    int extractMin1()
    {
        if (size == 0)
            return;
        if (size == 1)
        {
            size--;
            return arr[size];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        minHeapify(0);
        return arr[size];
    }
};

int main()
{
    MinHeap m(10);
    m.insert(5);
    m.insert(12);
    m.insert(45);
    m.insert(34);
    m.insert(11);
    m.print();
    // distorting root value then perform the heapify function
    // m.arr[0] = 40;
    // m.minHeapify(0);
    // m.print();
    cout << endl;
    cout << m.extractMin();
    cout << "Now the updated tree is:";
    m.print();
}