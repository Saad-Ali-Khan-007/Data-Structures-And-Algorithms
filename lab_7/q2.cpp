#include <iostream>
using namespace std;

class saad_lab7
{
public:
    int findWinner(int n, int k)
    {
        if (n == 1)
            return 0;
        else
            return (findWinner(n - 1, k) + k) % n;
    }

    int getWinner(int n, int k)
    {
        return findWinner(n, k) + 1;
    }
};

int main()
{
    saad_lab7 game;

    int n, k;
    cout << "Enter the number of friends (n): ";
    cin >> n;
    cout << "Enter the step count (k): ";
    cin >> k;

    int winner = game.getWinner(n, k);
    cout << "The winner of the game is friend number: " << winner << endl;

    return 0;
}
