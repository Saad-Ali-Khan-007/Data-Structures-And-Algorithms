#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class saad_lab4
{
public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        vector<int> res;
        int n = arr.size();

        for (int size = n; size > 1; --size)
        {

            int maxIndex = findMaxIndex(arr, size);

            if (maxIndex != size - 1)
            {

                if (maxIndex != 0)
                {
                    res.push_back(maxIndex + 1);
                    flip(arr, maxIndex + 1);
                }

                res.push_back(size);
                flip(arr, size);
            }
        }
        return res;
    }

private:
    int findMaxIndex(const vector<int> &arr, int size)
    {
        int maxIndex = 0;
        for (int i = 1; i < size; ++i)
        {
            if (arr[i] > arr[maxIndex])
            {
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    void flip(vector<int> &arr, int k)
    {
        reverse(arr.begin(), arr.begin() + k);
    }
};

int main()
{

    vector<int> arr = {3, 2, 4, 1};

    saad_lab4 sorter;

    vector<int> result = sorter.pancakeSort(arr);

    cout << "Sequence of pancake flips: ";
    for (int k : result)
    {
        cout << k << " ";
    }
    cout << endl;

    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
