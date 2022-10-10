#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid;

        while (low <= high)
        {
            mid = (low + high) / 2;
            if ( nums[mid] == target )
                return mid;
            else if ( nums[mid] > target )
                high = mid - 1;
            else
                low = mid + 1;
        }

        return -1;


    }
};

Solution sol;

int main(void)
{
	vector<int> vTest = {-1,0,3,5,9,12};
    cout << "result: " << sol.search(vTest, 9) << endl;

	return 0;
}