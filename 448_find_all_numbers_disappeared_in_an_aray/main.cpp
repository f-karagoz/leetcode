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
		sort(nums.begin(), nums.end());
		for (int i = 1; i <= nums.size(); ++i)
			if ( !binary_search(nums.begin(), nums.end(), i) )
				result.push_back(i);
		
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