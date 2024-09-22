#include <iostream>
using namespace std;

class saad_lab4
{
private:
    int arr[100];
    int size;

public:
    saad_lab4(int arr[], int size)
    {
        this->size = size;
        for (int i = 0; i < size; i++)
        {
            this->arr[i] = arr[i];
        }
    }

    void bubble_sort()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    void selection_sort()
    {
        for (int i = 0; i < size - 1; i++)
        {
            int min_idx = i;
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j] < arr[min_idx])
                {
                    min_idx = j;
                }
            }
            swap(arr[min_idx], arr[i]);
        }
    }

    void insertion_sort()
    {
        for (int i = 1; i < size; i++)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    void printArray()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void maxToys(int K)
    {
        int count = 0;
        int cost = 0;
        for (int i = 0; i < size; i++)
        {
            if (K >= arr[i])
            {
                cost += arr[i];
                count++;
            }
            else
            {
                break;
            }
        }
        cout << "Total cost is: " << cost << endl;
        cout << "Maximum number of toys you can buy: " << count << endl;
    }
};

int main()
{
    int arr[] = {1, 12, 5, 111, 200, 1000, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int K = 50;

    saad_lab4 bs(arr, size);
    cout << "Unsorted array: ";
    bs.printArray();

    cout << "Sorted array (Bubble Sort): ";
    bs.bubble_sort();
    bs.printArray();

    bs.maxToys(K);

    return 0;
}