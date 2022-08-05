#include <iostream>
using namespace std;
class array
{
    int n1, n2,n3;
    int arr1[100], arr2[100];
    int arr3[300];

public:
    void getArr()
    {
        cout << "Enter the size of the 1st array: ";
        cin >> n1;
        cout << "Enter the elements of the 1st array in sorted manner: ";
        for (int i = 0; i < n1; i++)
            cin >> arr1[i];

        cout << "Enter the size of the 2nd array: ";
        cin >> n2;
        cout << "Enter the elements of the 2nd array in sorted manner: ";
        for (int i = 0; i < n2; i++)
            cin >> arr2[i];
    }
    void merge_sort()
    {
        int i, j, k;
        i = j = k=0;

        while (i < n1 && j < n2)
        {
            if (arr1[i] <= arr2[j])
                arr3[k++] = arr1[i++];
            else
                arr3[k++] = arr2[j++];
        }

        while (i < n1)
            arr3[k++] = arr1[i++];
        while (j < n2)
            arr3[k++] = arr2[j++];
            n3=k;
    }
    void display(){
        for(int i=0;i<n3;i++)
        cout<<arr3[i]<<" ";
    }
};
int main()
{
    array A;
    A.getArr();
    A.merge_sort();
    A.display();
    return 0;
}