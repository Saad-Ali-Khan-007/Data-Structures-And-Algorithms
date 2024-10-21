#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class saad_lab5
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> timeline(1001, 0);

        for (auto &trip : trips)
        {
            timeline[trip[1]] += trip[0];
            timeline[trip[2]] -= trip[0];
        }

        int currentPassengers = 0;
        for (int passengers : timeline)
        {
            currentPassengers += passengers;
            if (currentPassengers > capacity)
                return false;
        }
        return true;
    }
};

int main()
{
    saad_lab5 obj;

    vector<vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};
    int capacity = 4;
    bool canCarryAll = obj.carPooling(trips, capacity);
    cout << "Can carry all passengers: " << (canCarryAll ? "Yes" : "No") << endl;

    return 0;
}
