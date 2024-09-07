#include <iostream>
#include <vector>
using namespace std;

int lab1()
{
    cout << "Name: Saad Ali Khan(SE-23083)" << endl;
    cout << "Lab 01" << endl;
    return 0;
}

class Matrix
{
private:
    vector<vector<int>> matrix;

public:
    Matrix(const vector<vector<int>> &mat) : matrix(mat) {}

    pair<int, int> binarySearch(int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return {-1, -1};

        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0, right = rows * cols - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int midElement = matrix[mid / cols][mid % cols];

            if (midElement == target)
            {

                return {mid / cols, mid % cols};
            }
            else if (midElement < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return {-1, -1};
    }
};

int q1()
{

    vector<vector<int>> mat = {
        {1, 3, 5},
        {7, 9, 11},
        {13, 15, 17}};

    Matrix m(mat);
    int target;
    cout << "Enter element to search: ";
    cin >> target;

    pair<int, int> result = m.binarySearch(target);

    if (result.first != -1)
    {
        cout << "Element found at position (" << result.first + 1 << ", " << result.second + 1 << ")." << endl;
    }
    else
    {
        cout << "Element not found in the matrix." << endl;
    }

    return 0;
}

int main()
{
    lab1();
    q1();
    return 0;
}