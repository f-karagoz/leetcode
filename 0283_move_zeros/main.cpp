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
        // aproach: iterate over the the range [1:n]
        // two pointers: li, ri
        // the left index check for zero
        // if so move the right index till non-zero found
        // copy right index value to left index
        // change right index value to zero

        int li = 0;
        int ri = 1;

        for (int li = 0, ri = 1; li < nums.size(); ++li, ri = li + 1)   // O(n-k)
        {
            if (nums[li] == 0)
                for (; ri < nums.size(); ++ri)                          // O(n)
                    if (nums[ri] != 0)              // search for non-zero element
                    { 
                        nums[li] = nums[ri];        // copy the non-zero element to li index
                        nums[ri] = 0;               // set ri index to zero
                        break;
                    }
            // if no none-zero element found operation is done
            // no need to iterate over the remaining indexes of input array
            if (ri == nums.size())
                break;

        }
    }
};

Solution sol;

int main(void)
{
    /*
    Input: nums = [0,1,0,3,12]
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