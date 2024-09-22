#include <iostream>
#include <ctime>
#include <cstdlib>
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

    void bubbleSort()
    {
        int comparisons = 0;
        int swaps = 0;

        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                comparisons++;
                if (arr[j] > arr[j + 1])
                {
                    swaps++;
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

        cout << "Bubble Sort: Comparisons = " << comparisons << ", Swaps = " << swaps << endl;
    }

    void selectionSort()
    {
        int comparisons = 0;
        int swaps = 0;

        for (int i = 0; i < size - 1; i++)
        {
            int min_idx = i;
            for (int j = i + 1; j < size; j++)
            {
                swaps++;
                if (arr[j] < arr[min_idx])
                {
                    min_idx = j;
                }
            }
            comparisons++;
            swap(arr[min_idx], arr[i]);
        }

        cout << "Selection Sort: Comparisons = " << comparisons << ", Swaps = " << swaps << endl;
    }

    void insertionSort()
    {
        int comparisons = 0;
        int swaps = 0;

        for (int i = 1; i < size; i++)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                swaps++;
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            comparisons++;
            arr[j + 1] = key;
        }

        cout << "Insertion Sort: Comparisons = " << comparisons << ", Swaps = " << swaps << endl;
    }

    void analyzeRandomArray(int size)
    {
        srand(time(0));
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 100;
        }

        cout << "Random Array: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        bubbleSort();
        selectionSort();
        insertionSort();
    }
};

int main()
{
    int arr[] = {1, 12, 5, 111, 200, 1000, 10, 32};
    int size = sizeof(arr) / sizeof(arr[0]);

    saad_lab4 sort(arr, size);

    cout << "Analysis on Random Array:" << endl;
    sort.analyzeRandomArray(20);

    return 0;
}