#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an array nums of n integers where nums[i] is in the range [1, n]
return an array of all the integers in the range [1, n] that do not appear in nums.
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
	{
		vector<int> result;

		// sort and binary search
		// buble sort
		for (int i = 0; i < nums.size() - 1; ++i)
			for (int j = 0; j < nums.size() - 1 - i; ++j)
				if (nums[j + 1] < nums[j])
				{
					auto temp = nums[j + 1];
					nums[j + 1] = nums[j];
					nums[j] = temp;
				}

		// binary search for each i index
		for (int i = 1; i <= nums.size(); ++i)
		{
			int foundFlag = 0;
			int low = 0;
			int high = nums.size() - 1;
			int mid;

			while (low <= high)
			{
				mid = low + (high - low) / 2;
				if (nums[mid] == i)
				{
					foundFlag = 1;
					break;
				}
				else if (nums[mid] > i)
					high = mid - 1;
				else
					low = mid + 1;
			}

			if (foundFlag == 0)
				result.push_back(i);
		}
		
		return result;
    }
};

Solution sol;

int main(void)
{
	cout << "hellow" << endl;

	vector<int> vTest = { 4,3,2,7,8,2,3,1 };
	vector<int> res = sol.findDisappearedNumbers(vTest);
	
	for (auto x : res)
		cout << x << ", ";
	cout << endl;

	return 0;
}