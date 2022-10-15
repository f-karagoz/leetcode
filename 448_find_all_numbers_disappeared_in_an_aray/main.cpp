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

		// brute-force
		// linear search for each i index [0:n]
		for (int i = 1; i <= nums.size(); ++i)
			if (find(nums.begin(), nums.end(), i) == end(nums))
				result.push_back(i);

		return result;
    }
};

Solution sol;

int main(void)
{
	cout << "hellow" << endl;

	vector<int> vTest = { 5,2,3,4 };

	sol.findDisappearedNumbers(vTest); 
	return 0;
}