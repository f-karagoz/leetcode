#include <iostream>
#include <vector>
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
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i)
            result.push_back(square(nums[i]));

        int changedFlag = 0;
        for (int i = 0; i < result.size() - 1; ++i)
        {
            changedFlag = 0;
            for (int j = 0; j < result.size() - 1 - i; ++j)
                if (result[j + 1] < result[j])
                {
                    int temp = result[j + 1];
                    result[j + 1] = result[j];
                    result[j] = temp;
                    changedFlag = 1;
                }
            if (changedFlag == 0)
                break;
        }


        return result;
    }
};

Solution sol;

int main(void)
{

    vector<int> vTest = { -4,-1,0,3,10 }; // expected after method 0,1,9,16,100

    //cout << "Test result is : " << sol.sortedSquares(vTest) << endl;

    for (auto x : sol.sortedSquares(vTest))
        cout << x << " ";
    cout << endl;
    return 0;
}