#include <iostream>
#include <string>
#include <vector>
using namespace std;

class saad_lab9_BrowserHistory
{
private:
    vector<string> history;
    int currentIndex;

public:
    saad_lab9_BrowserHistory(string homepage)
    {
        history.push_back(homepage);
        currentIndex = 0;
    }

    void visit(string url)
    {
        history.resize(currentIndex + 1);
        history.push_back(url);
        currentIndex++;
    }

    string back(int steps)
    {
        currentIndex = max(0, currentIndex - steps);
        return history[currentIndex];
    }

    string forward(int steps)
    {
        currentIndex = min((int)history.size() - 1, currentIndex + steps);
        return history[currentIndex];
    }
};

int main()
{
    saad_lab9_BrowserHistory browserHistory("leetcode.com");
    browserHistory.visit("google.com");
    browserHistory.visit("facebook.com");
    browserHistory.visit("youtube.com");
    cout << browserHistory.back(1) << endl;
    cout << browserHistory.back(1) << endl;
    cout << browserHistory.forward(1) << endl;
    browserHistory.visit("linkedin.com");
    cout << browserHistory.forward(2) << endl;
    cout << browserHistory.back(2) << endl;
    cout << browserHistory.back(7) << endl;
}
