#include <iostream>
#include <vector>
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

		int* temp = (int*)calloc(nums.size(), sizeof(int));
		for (int i = 0; i < nums.size(); ++i )
			temp[nums[i]-1] = 1;	// 1 is a dummy value
			
		for (int i = 0; i < nums.size(); ++i)
			if (temp[i] == 0)
				result.push_back(i + 1);

		return result;

    }
};

Solution sol;

int main(void)
{
	cout << "hellow" << endl;
	return 0;
}