#include <iostream>
#include <bits/stdc++.h.txt>
using namespace std;

class MinHeap
{
public:
    int *arr;
    int size; // size of heap at a particular instance
    int n;    // capacity of heap

    MinHeap(int c)
    {
        arr = new int[c];
        size = 0;
        n = c;
    }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    int parent(int i) { return ((i - 1) / 2); }

    void insert(int a)
    {

        if (size >= n)
        {
            cout << "Overflow";
            return;
        }
        else
        {
            size++;
            arr[size - 1] = a;
            int x = size - 1;

            while (x != 0)
            {
                if (arr[parent(x)] > arr[x])
                {
                    swap(arr[x], arr[parent(x)]);
                    x = parent(x);
                }
                else
                    return;
            }
        }
    }
    // time complexity = O(log(h))  --here h is the height of tree

    // ✍️ Heapify - its a process of placing the elements in the correct position so that it stiesfies the heap property
    // time complexity = 0(h) or O(logn)

    void heapify(int i)
    {
        int l = left(i),
            r = right(i),
            smallest = i;

        if (l < size && arr[l] < arr[i])
        {
            smallest = l;
        }
        if (r < size && arr[r] < arr[smallest])
        {
            smallest = r;
        }

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    // Extract min
    // Here we removing the minimum elemen of the heap
    // In case of min heap its the root element so me have to remove the first element
    // For extracting the min. element we remove the first element and replace it with  the last one then heapify.

    auto extractMin()
    {
        if (size == 0)
        {

            return INT_MAX;
        }
        if (size == 1)
        {
            size--;
            return arr[size];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        heapify(0);
        return arr[size];
    }

    // printing the heap
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    void decreaseKey(int i, int x)
    {
        arr[i] = x;
        // heapify(i);
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
};

int main()
{
    MinHeap m(10);
    m.insert(10);
    m.insert(20);
    m.insert(40);
    m.insert(80);
    m.insert(100);
    m.insert(70);
    m.print();
    cout << m.size;
    // m.decreaseKey(3, 5);
    cout << endl;
    cout << m.extractMin();
    cout << endl;
    m.print();
}