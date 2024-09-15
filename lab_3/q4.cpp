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
public:
    bool backspaceCompare(string S, string T)
    {
        return getResStack(S) == getResStack(T);
    }

private:
    string getResStack(const string &s)
    {
        string result;
        for (char c : s)
        {
            if (c == '#')
            {
                if (!result.empty())
                {
                    result.pop_back();
                }
            }
            else
            {
                result.push_back(c);
            }
        }
        return result;
    }
};

int q4()
{
    string S, T;
    cout << "Enter first string (S): ";
    cin >> S;
    cout << "Enter second string (T): ";
    cin >> T;

    saad_lab3 solution;
    bool result = solution.backspaceCompare(S, T);

    if (result)
    {
        cout << "The strings are equal after backspace processing." << endl;
    }
    else
    {
        cout << "The strings are not equal after backspace processing." << endl;
    }
    return 0;
}

int main()
{
    lab1();
    q4();
    return 0;
}