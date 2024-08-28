#include <iostream>
using namespace std;

int lab1()
{
    cout << "Name: Saad Ali Khan(SE-23083)" << endl;
    cout << "Lab 01" << endl;
    return 0;
}

// 1.Write a C++ program to copy data of a 2D array in a 1D array using Column Major Order.

int q1()
{
    int const row = 3;
    int const col = 3;
    int two_dim_array[row][col] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    int one_dim_array[row * col];

    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            one_dim_array[j * row + i] = two_dim_array[i][j];
        }
    }

    for (int i = 0; i < row * col; i++)
    {
        cout << one_dim_array[i];
    }
    return 0;
}

int main()
{
    lab1();
    q1();
    return 0;
}