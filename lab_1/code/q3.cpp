#include <iostream>
using namespace std;

int lab1()
{
    cout << "Name: Saad Ali Khan(SE-23083)" << endl;
    cout << "Lab 01" << endl;
    return 0;
}

class MedianFinder
{
private:
    int *nums;
    int size;
    int capacity;

public:
    MedianFinder()
    {
        size = 0;
        capacity = 1;
        nums = new int[capacity];
    }
    ~MedianFinder()
    {
        delete[] nums;
    }
    void addNum(int num)
    {
        if (size == capacity)
        {
            int *temp = new int[capacity * 2];

            capacity = capacity * 2;
            for (int i = 0; i < size; i++)
            {
                temp[i] = nums[i];
            }

            delete[] nums;
            nums = temp;
        }
        int i = size - 1;
        while (i >= 0 && nums[i] > num)
        {
            nums[i + 1] = nums[i];
            i--;
        }
        nums[i + 1] = num;
        size++;
    }
    double findMedian()
    {
        if (size % 2 == 0)
        {
            return (nums[size / 2 - 1] + nums[size / 2]) / 2.0;
        }
        else
        {
            return nums[size / 2];
        }
    }
};

int q3()
{
    MedianFinder medFind;
    medFind.addNum(1);
    medFind.addNum(2);
    cout << medFind.findMedian() << endl;
    medFind.addNum(3);
    cout << medFind.findMedian() << endl;
    return 0;
}

int main()
{
    lab1();
    q3();
    return 0;
}