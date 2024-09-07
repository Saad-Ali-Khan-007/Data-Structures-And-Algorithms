#include <iostream>
#include <vector>
using namespace std;

int lab1()
{
    cout << "Name: Saad Ali Khan(SE-23083)" << endl;
    cout << "Lab 01" << endl;
    return 0;
}

class VectorOperations
{
private:
    vector<int> A, B;
    int X, Y;

public:
    VectorOperations(const vector<int> &a, const vector<int> &b, int x, int y)
        : A(a), B(b), X(x), Y(y) {}

    vector<int> calculateXA_YB()
    {
        vector<int> result(A.size());
        for (size_t i = 0; i < A.size(); i++)
        {
            result[i] = X * A[i] + Y * B[i];
        }
        return result;
    }

    int dotProduct()
    {
        int result = 0;
        for (size_t i = 0; i < A.size(); i++)
        {
            result += A[i] * B[i];
        }
        return result;
    }
};

int q3()
{
    vector<int> A = {16, -6, 7};
    vector<int> B = {4, 2, -3};
    int X = 2, Y = -5;

    VectorOperations vo(A, B, X, Y);

    vector<int> result = vo.calculateXA_YB();
    int dotProduct = vo.dotProduct();

    cout << "Result of XA + YB: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Dot product of A and B: " << dotProduct << endl;
    return 0;
}

int main()
{
    lab1();
    q3();
    return 0;
}