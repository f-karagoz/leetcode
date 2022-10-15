#include <iostream>
#include <vector>
#include <cstdlib>       // abs()
using namespace std;

/*
Given an integer array nums sorted in non-decreasing order,
return an array of the squares of each number sorted in non-decreasing order.
Target: O(n) runtime complexity.
*/

class Solution {
    int square(int x) { return x * x; }
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int> result(nums.size());

        // two pointers aproach
        int l = 0;
        int r = nums.size() - 1;

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (abs(nums[l]) > abs(nums[r]))
            {
                result[i] = nums[l] * nums[l];
                l++;
            }  
            else
            {
                result[i] = nums[r] * nums[r];
                r--;
            }
        }

        return result;
    }
};

Solution sol;

int main(void)
{
    vector<int> vTest = { -4,-1,0,3,10 }; // expected after method 0,1,9,16,100

    for (auto x : sol.sortedSquares(vTest))
        cout << x << " ";
    cout << endl;

    return 0;
}