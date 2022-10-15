#include <iostream>
#include <vector>
//#include <algorithm>
#include <unordered_set>
using namespace std;

/*
Given an array nums of n integers where nums[i] is in the range [1, n]
return an array of all the integers in the range [1, n] that do not appear in nums.
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
	{
		// hashset
		// insert every nums[i] into hashset. t: O(n), m: O(n)		
		unordered_set<int> s(begin(nums), end(nums));

		vector<int> result;

		// iterate over range and insert elements. t: O(n) 
		for (int i = 1; i <= size(nums); ++i)
			if (s.count(i) == 0)
				result.push_back(i);
		
		return result;
		// Total: time complexity: O(2n), memory compelexity O(n)
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