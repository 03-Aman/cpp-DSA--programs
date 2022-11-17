#include <bits/stdc++.h>
using namespace std;
class heap
{
public:
    int arr[1000];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int d)
    {
        size += 1;
        int index = size;
        arr[index] = d;
        while (index > 1)
        {
            int parent = index / 2; // index/2 pe parent hai
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete!" << endl;
            return;
        }
        arr[1] = arr[size]; // first waali node pe last waali node ki value daal di

        // remove last element
        size--;

        // take root to it's correct position
        int i = 1;
        while (i < size)
        {
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;
            if (leftChild < size && arr[i] < arr[leftChild])
            {
                swap(arr[i], arr[leftChild]);
                i = leftChild;
            }
            else if (rightChild < size && arr[i] < arr[rightChild])
            {
                swap(arr[i], arr[rightChild]);
                i = rightChild;
            }
            else
                return;
        }
    }
};
void heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[largest] < arr[left])
        largest = left;
    if (right <= n && arr[largest] < arr[right])
        largest = right;
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
    else
        return;
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteFromHeap();
    h.print();
    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i >= 1; i--)
        heapify(arr, 6, i);
    cout << "Printing the array after calling heapify :";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    return 0;
}