#include <iostream>
using namespace std;

void saad_lab4_bubbleSort(int *arr, int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {

                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {5, 1, 4, 2, 8};
    int N = sizeof(arr) / sizeof(arr[0]);
    saad_lab4_bubbleSort(arr, N);
    cout << "Sorted array:\n";
    printArray(arr, N);
    return 0;
}
