#include <iostream>
#include <stack>
using namespace std;

class saad_lab5
{
public:
    void quickSortIterative(int arr[], int n)
    {
        stack<int> s;
        s.push(0);
        s.push(n - 1);

        while (!s.empty())
        {
            int high = s.top();
            s.pop();
            int low = s.top();
            s.pop();

            if (low < high)
            {
                int p = partition(arr, low, high);

                if (p - 1 > low)
                {
                    s.push(low);
                    s.push(p - 1);
                }

                if (p + 1 < high)
                {
                    s.push(p + 1);
                    s.push(high);
                }
            }
        }
    }

private:
    int partition(int arr[], int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }
};
int main()
{
    saad_lab5 obj;

    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    obj.quickSortIterative(arr, n);
    cout << "Sorted array using QuickSort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}