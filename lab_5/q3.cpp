#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class saad_lab5
{
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
    {
        vector<vector<int>> merged;
        if (intervals.empty())
            return merged;

        sort(intervals.begin(), intervals.end());

        merged.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (merged.back()[1] >= intervals[i][0])
            {
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            }
            else
            {
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};

int main()
{
    saad_lab5 obj;

    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> mergedIntervals = obj.mergeIntervals(intervals);
    cout << "Merged Intervals: ";
    for (auto interval : mergedIntervals)
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    cout << endl;

    return 0;
}
