#include <bits/stdc++.h>
using namespace std;
void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];
    int k = s;
    for (int i = 0; i < len1; i++)
        first[i] = arr[k++];
    for (int i = 0; i < len2; i++)
        second[i] = arr[k++];
    // merge
    int in1 = 0;
    int in2 = 0;
    int mainArrayIndex = s;
    while (in1 < len1 && in2 < len2)
    {
        if (first[in1] < second[in2])
            arr[mainArrayIndex++] = first[in1++];
        else
            arr[mainArrayIndex++] = second[in2++];
    }
    while (in1 < len1)
        arr[mainArrayIndex++] = first[in1++];
    while (in2 < len2)
        arr[mainArrayIndex++] = second[in2++];
    delete[] first;
    delete[] second;
}
void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
        return;
    int mid = (s + e) / 2;
    // left part sort karna hai
    mergeSort(arr, s, mid);
    // right part sort karna hai
    mergeSort(arr, mid + 1, e);
    // merge
    merge(arr, s, e);
}
int main()
{
    int arr[] = {1, 2, 3, 5, 4, 0};
    mergeSort(arr, 0, 6);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
    return 0;
}