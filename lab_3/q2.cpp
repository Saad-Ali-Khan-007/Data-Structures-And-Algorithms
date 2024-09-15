#include <iostream>
using namespace std;

int lab1()
{
    cout << "Name: Saad Ali Khan(SE-23083)" << endl;
    cout << "Lab 01" << endl;
    return 0;
}

class saad_lab3
{
private:
    char *stack_arr;
    int topIndex;
    int capacity;

    void resize()
    {
        char *newstack_arr = new char[capacity * 2];
        for (int i = 0; i < capacity; i++)
        {
            newstack_arr[i] = stack_arr[i];
        }
        delete[] stack_arr;
        stack_arr = newstack_arr;
        capacity *= 2;
    }

public:
    saad_lab3(int size = 10)
    {
        stack_arr = new char[size];
        capacity = size;
        topIndex = -1;
    }

    ~saad_lab3()
    {
        delete[] stack_arr;
    }

    void push(char value)
    {
        if (topIndex == capacity - 1)
        {
            resize();
        }
        stack_arr[++topIndex] = value;
    }

    bool isEmpty()
    {
        return topIndex == -1;
    }
    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow";
        }
        return stack_arr[topIndex--];
    }
};

void reverseString(const string &input)
{
    saad_lab3 stack(input.length());

    for (int i = 0; i < input.length(); i++)
    {
        stack.push(input[i]);
    }

    cout << "Reversed String: ";
    while (!stack.isEmpty())
    {
        cout << stack.pop();
    }
    cout << endl;
}

bool isPalindrome(const string &input)
{
    saad_lab3 stack(input.length());

    for (int i = 0; i < input.length(); i++)
    {
        stack.push(input[i]);
    }

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] != stack.pop())
        {
            return false;
        }
    }
    return true;
}

int q2_q3()
{
    string input1;
    cout << "Enter a string to reverse: ";
    cin >> input1;

    reverseString(input1);

    string input;
    cout << "Enter a string to check for palindrome: ";
    cin >> input;

    if (isPalindrome(input))
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}

int main()
{
    lab1();
    q2_q3();
    return 0;
}