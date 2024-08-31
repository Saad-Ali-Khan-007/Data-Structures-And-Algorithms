#include <iostream>
using namespace std;

int lab1()
{
    cout << "Name: Saad Ali Khan(SE-23083)" << endl;
    cout << "Lab 01" << endl;
    return 0;
}

bool searchMatrix(int matrix[][4], int m, int n, int target)
{
    if (m == 0 || n == 0)
        return false;
    int left = 0;
    int right = m * n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int mid_value = matrix[mid / n][mid % n];
        if (mid_value == target)
        {
            return true;
        }
        else if (mid_value < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}
int q5()
{

    int matrix[3][4] = {{1, 3, 5, 7},
                        {10, 11, 16, 20},
                        {23, 30, 34, 60}};
    int target = 3;
    bool result = searchMatrix(matrix, 3, 4, target);
    if (result)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}

int main()
{
    lab1();
    q5();
    return 0;
}