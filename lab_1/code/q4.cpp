#include <iostream>
using namespace std;

int lab1()
{
    cout << "Name: Saad Ali Khan(SE-23083)" << endl;
    cout << "Lab 01" << endl;
    return 0;
}

int binarySearch(const int nums[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int q4()
{
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target1 = 9;
    int target2 = 2;
    int result1 = binarySearch(nums, size, target1);
    int result2 = binarySearch(nums, size, target2);
    cout << "Index of " << target1 << " is: " << result1 << endl;
    cout << "Index of " << target2 << " is: " << result2 << endl;
    return 0;
}

int main()
{
    lab1();
    q4();
    return 0;
}