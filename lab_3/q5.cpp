#include <iostream>
#include <stack>
using namespace std;

int lab3()
{
    cout << "Name: Saad Ali Khan(SE-23083)" << endl;
    cout << "Lab 03" << endl;
    return 0;
}

void generateFibonacci(int n)
{
    stack<int> fibStack;

    int a = 1, b = 1;

    if (n <= 0)
    {
        cout << "Invalid input! Number of terms should be positive." << endl;
        return;
    }

    fibStack.push(a);

    if (n > 1)
    {
        fibStack.push(b);
    }

    for (int i = 3; i <= n; i++)
    {
        int next = a + b;
        fibStack.push(next);
        a = b;
        b = next;
    }

    cout << "Fibonacci series in reverse order: ";
    while (!fibStack.empty())
    {
        cout << fibStack.top() << " ";
        fibStack.pop();
    }
    cout << endl;
}

int q5()
{
    int n;

    cout << "Enter the number of terms for Fibonacci series: ";
    cin >> n;

    generateFibonacci(n);

    return 0;
}

int main()
{
    lab3();
    q5();
    return 0;
}