#include <iostream>
using namespace std;
class array
{
    int arr[100];
    int n;
    // int lb = 0;
    // int ub = n - 1;

public:
    void getarr(int n)
    {
        this->n = n;
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }
    void Displayarr()
    {
        cout << "The sorted array is: ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }
    int partition(int lb, int ub)
    {

        int left = lb;
        int right = ub;
        int pivot = arr[left];
        int cnt = 0;
        for (int i = left + 1; i <= right; i++)
        {
            if (arr[i] < pivot)
            {
                cnt++;
            }
        }

        int pivotIndex = left + cnt;

        swap(arr[left], arr[pivotIndex]);

        while (left < right)
        {
            for (; (arr[left] <= pivot) && (left <= ub); left++)
                ;
            for (; (arr[right] > pivot) && (right >= lb); right--)
                ;

            if (left < right)
                swap(arr[left], arr[right]);
        }
        swap(pivot, arr[right]);

        return right;
    }
    void quickSort(int lb, int ub)
    {
        if (lb >= ub)
            return;
        int splitPt;

        splitPt = partition(lb, ub);
        // cout << "jhj" << lb << " " << ub;

        quickSort(lb, splitPt - 1);
        quickSort(splitPt + 1, ub);
    }
};
int main()
{
    int n;
    cout << "Enter the size of tha array: ";
    cin >> n;
    array a;
    a.getarr(n);
    a.quickSort(0, n - 1);
    a.Displayarr();
    return 0;
}