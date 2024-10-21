#include <iostream>
#include <vector>
using namespace std;

class saad_lab5
{
public:
    void mergeSortIterative(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> temp(n);

        for (int curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
        {
            for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size)
            {
                int mid = min(left_start + curr_size - 1, n - 1);
                int right_end = min(left_start + 2 * curr_size - 1, n - 1);
                merge(arr, temp, left_start, mid, right_end);
            }
        }
    }

private:
    void merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right)
    {
        int i = left, j = mid + 1, k = left;

        while (i <= mid && j <= right)
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
            }
        }
        while (i <= mid)
            temp[k++] = arr[i++];
        while (j <= right)
            temp[k++] = arr[j++];

        for (i = left; i <= right; i++)
            arr[i] = temp[i];
    }
};

int main()
{
    saad_lab5 obj;

    vector<int> arr2 = {12, 11, 13, 5, 6, 7};
    obj.mergeSortIterative(arr2);
    cout << "Sorted array using MergeSort: ";
    for (int num : arr2)
        cout << num << " ";
    cout << endl;

    return 0;
}
