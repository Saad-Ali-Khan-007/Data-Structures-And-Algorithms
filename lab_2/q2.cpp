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
    vector<vector<int>> mat;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c)
    {
        mat.resize(rows, vector<int>(cols, 0));
    }

    void inputMatrix()
    {
        cout << "Enter matrix elements (" << rows << "x" << cols << "):" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> mat[i][j];
            }
        }
    }

    void display() const
    {
        for (const auto &row : mat)
        {
            for (int elem : row)
            {
                cout << elem << " ";
            }
            cout << endl;
        }
    }

    Matrix add(const Matrix &other)
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    Matrix subtract(const Matrix &other)
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.mat[i][j] = mat[i][j] - other.mat[i][j];
            }
        }
        return result;
    }

    Matrix multiply(const Matrix &other)
    {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.cols; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    Matrix scalarMultiply(int scalar)
    {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.mat[i][j] = mat[i][j] * scalar;
            }
        }
        return result;
    }

    Matrix transpose()
    {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.mat[j][i] = mat[i][j];
            }
        }
        return result;
    }
};

int q2()
{
    int r, c;
    cout << "Enter rows and columns for matrices: ";
    cin >> r >> c;

    Matrix mat1(r, c), mat2(r, c);
    mat1.inputMatrix();
    mat2.inputMatrix();

    Matrix sum = mat1.add(mat2);
    Matrix diff = mat1.subtract(mat2);
    Matrix prod = mat1.multiply(mat2);

    cout << "Matrix 1 + Matrix 2:" << endl;
    sum.display();

    cout << "Matrix 1 - Matrix 2:" << endl;
    diff.display();

    cout << "Matrix 1 * Matrix 2:" << endl;
    prod.display();

    int scalar = 3;
    Matrix scalarProd = mat1.scalarMultiply(scalar);
    Matrix scalarTrans = scalarProd.transpose();

    cout << "Matrix 1 * " << scalar << " (scalar multiplication):" << endl;
    scalarProd.display();

    cout << "Transpose of the matrix after scalar multiplication:" << endl;
    scalarTrans.display();

    return 0;
}

int main()
{
    lab1();
    q2();
    return 0;
}