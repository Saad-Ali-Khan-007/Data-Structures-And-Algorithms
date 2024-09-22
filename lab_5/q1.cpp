#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class saad_lab5
{
public:
    void mergeSort(vector<int> &arr)
    {
        int n = arr.size();

        for (int subArraySize = 1; subArraySize < n; subArraySize *= 2)
        {
            for (int leftStart = 0; leftStart < n; leftStart += 2 * subArraySize)
            {
                int mid = min(leftStart + subArraySize - 1, n - 1);
                int rightEnd = min(leftStart + 2 * subArraySize - 1, n - 1);
                if (mid < rightEnd)
                {
                    merge(arr, leftStart, mid, rightEnd);
                }
            }
        }
    }

    void quickSort(vector<int> &arr)
    {
        if (arr.empty())
            return;

        stack<int> stack;
        stack.push(0);
        stack.push(arr.size() - 1);

        while (!stack.empty())
        {
            int high = stack.top();
            stack.pop();
            int low = stack.top();
            stack.pop();

            if (low < high)
            {
                int pivotIndex = partition(arr, low, high);

                stack.push(low);
                stack.push(pivotIndex - 1);

                stack.push(pivotIndex + 1);
                stack.push(high);
            }
        }
    }

    void printArray(const vector<int> &arr) const
    {
        for (int num : arr)
        {
            cout << num << " ";
        }
        cout << endl;
    }

private:
    void merge(vector<int> &arr, int left, int mid, int right)
    {
        vector<int> leftPart(arr.begin() + left, arr.begin() + mid + 1);
        vector<int> rightPart(arr.begin() + mid + 1, arr.begin() + right + 1);

        int i = 0, j = 0, k = left;

        while (i < leftPart.size() && j < rightPart.size())
        {
            if (leftPart[i] <= rightPart[j])
            {
                arr[k++] = leftPart[i++];
            }
            else
            {
                arr[k++] = rightPart[j++];
            }
        }

        while (i < leftPart.size())
        {
            arr[k++] = leftPart[i++];
        }

        while (j < rightPart.size())
        {
            arr[k++] = rightPart[j++];
        }
    }

    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
};

int main()
{
    saad_lab5 sorter;

    vector<int> mergeSortArray = {34, 7, 23, 32, 5, 62};
    cout << "Original array for Merge Sort: ";
    sorter.printArray(mergeSortArray);

    sorter.mergeSort(mergeSortArray);
    cout << "Sorted array using Merge Sort: ";
    sorter.printArray(mergeSortArray);

    vector<int> quickSortArray = {34, 7, 23, 32, 5, 62};
    cout << "Original array for Quick Sort: ";
    sorter.printArray(quickSortArray);

    sorter.quickSort(quickSortArray);
    cout << "Sorted array using Quick Sort: ";
    sorter.printArray(quickSortArray);

    return 0;
}
