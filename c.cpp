#include <iostream>
using namespace std;
class array
{
    int arr[100];
    int size;
    int maximum, minimum;

public:
    void input(int s)
    {
        size = s;
        cout << "Enter the elements of array: ";
        for (int i = 0; i < size; i++)
            cin >> arr[i];
    }
    void max()
    {
        int max1 = arr[0], max2 = arr[1];
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > max1)
            {
                max2 = max1;
                max1 = arr[i];
            }
        }
        this->maximum = max1;
        cout << "The maximum and second maximum are : " << max1 << " " << max2 << endl;
    }
    void min()
    {
        int min1 = arr[0], min2 = arr[1];
        for (int i = 0; i < size; i++)

        {
            if (arr[i] < min1)
            {
                min2 = min1;
                min1 = arr[i];
            }
        }
        this->minimum = min1;
        cout << "The minimum and second minimum are : " << min1 << " " << min2 << endl;
    }
    void diff()
    {
        int difference = maximum - minimum;
        cout << "The maximum difference of the two elements of array is=> " << difference << endl;
    }
    void del(int in)
    {
        for (int i = in; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
        cout << "The array after deleting the element is: ";

        for (int i = 0; i < size - 1; i++)
        {
            cout << arr[i] << " ";
        }
    }
    void missing()
    {
        cout << "The missing elements are=> ";

        for (int i = 1; i < size + 1; i++)
        {
            int flag = 1;
            for (int j = 0; j < size; j++)
                if (arr[j] == i)
                    flag = 0;
            if (flag)
                cout << i << " ";
        }
    }
};
int main()
{
    array a1;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    a1.input(n);
    // a1.min();
    // a1.max();
    // a1.diff();
    a1.missing();
    return 0;
}