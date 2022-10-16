#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer array nums, move all 0's to the end of it 
while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // aproach: iterate over rage [1:n]
        // when zero found shift the array by one to the left
        // change last non-zero element to zero (last non-zero element was copied to left)
        int zeroCount = 0;
        for (int i = 0; i < nums.size() - 1 - zeroCount ; ++i)
        {
            if (nums[i] == 0)
            {
                zeroCount++;

                for (int j = i; j < nums.size() - zeroCount; ++j)
                {
                    nums[j] = nums[j + 1];
                }

                nums[nums.size() - zeroCount] = 0;
            }
        }
    }
};

Solution sol;

int main(void)
{
    /*
    * Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]
    */
    vector<int> vTest = { 0,1,0,3,12 };
    
    for (auto x : vTest)
        cout << x << ", ";
    cout << endl;

    sol.moveZeroes(vTest);

    for (auto x : vTest)
        cout << x << ", ";
    cout << endl;

    return 0;
}