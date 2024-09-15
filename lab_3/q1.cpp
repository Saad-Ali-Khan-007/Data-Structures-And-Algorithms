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
    int *stack_arr;
    int topIndex;
    int capacity;

    void resize()
    {
        int *newstack_arr = new int[capacity * 2];
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
        stack_arr = new int[size];
        capacity = size;
        topIndex = -1;
    }

    ~saad_lab3()
    {
        delete[] stack_arr;
    }

    void push(int value)
    {
        if (topIndex == capacity - 1)
        {
            resize();
        }

        stack_arr[++topIndex] = value;
    }

    int pop()
    {
        if (empty())
        {
            cout << "Stack underflow";
        }
        return stack_arr[topIndex--];
    }

    int peek()
    {
        if (empty())
        {
            cout << "stack is empty";
        }
        return stack_arr[topIndex];
    }

    bool empty()
    {
        return topIndex == -1;
    }

    int size()
    {
        return topIndex + 1;
    }

    void display()
    {
        if (empty())
        {
            cout << "stack is empty." << endl;
            return;
        }
        for (int i = 0; i <= topIndex; i++)
        {
            cout << stack_arr[i] << " ";
        }
        cout << endl;
    }
};

int q1()
{
    saad_lab3 saad_lab3;

    saad_lab3.push(10);
    saad_lab3.push(20);
    saad_lab3.push(30);
    saad_lab3.display();

    cout << "topIndex element is: " << saad_lab3.peek() << endl;
    cout << "stack size is: " << saad_lab3.size() << endl;

    saad_lab3.pop();
    saad_lab3.display();
    cout << "stack size after pop: " << saad_lab3.size() << endl;

    return 0;
}

int main()
{
    lab1();
    q1();
    return 0;
}