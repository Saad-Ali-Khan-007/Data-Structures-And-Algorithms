#include <iostream>
using namespace std;

class saad_lab4
{
public:
    void sortColors(int nums[], int n)
    {
        int red = 0, white = 0, blue = n - 1;

        while (white <= blue)
        {
            if (nums[white] == 0)
            {
                swap(nums[red++], nums[white++]);
            }
            else if (nums[white] == 2)
            {
                swap(nums[white], nums[blue--]);
            }
            else
            {
                white++;
            }
        }
    }
};

int main()
{
    int arr[] = {2, 0, 2, 1, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    saad_lab4 slab;

    cout << "Unsorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    slab.sortColors(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
