#include <iostream>
#include <vector>
using namespace std;
/*
Given a sorted array of distinct integers and a target value,
return the index if the target is found.
If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while ( low <= high )
        {
            mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        return low;
    }
};

Solution sol;

int main(void)
{

    vector<int> vTest = { 1,3,5,6 };

    cout << "Test result is : " << sol.searchInsert(vTest, 5) << endl;
	return 0;
}