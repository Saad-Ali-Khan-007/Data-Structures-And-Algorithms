#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class saad_lab5
{
public:
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> count;
        for (int num : nums)
        {
            count[num]++;
        }

        int longest = 0;
        for (auto it : count)
        {
            if (count.find(it.first + 1) != count.end())
            {
                longest = max(longest, it.second + count[it.first + 1]);
            }
        }
        return longest;
    }
};

int main()
{
    saad_lab5 obj;

    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    int longestHarmonious = obj.findLHS(nums);
    cout << "Longest Harmonious Subsequence length: " << longestHarmonious << endl;

    return 0;
}
