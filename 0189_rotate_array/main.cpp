#include <iostream>
#include <vector>
using namespace std;

/*
Given an array, rotate the array to the right
by k steps, where k is non-negative.
*/

class Solution
{
public:
	void rotate(vector<int>& nums, int k)
	{
		for (int i = 0; i < k; ++i)
		{
			int temp = nums[nums.size() - 1];

			for (int j = nums.size() - 1; j > 0; --j)
				nums[j] = nums[j - 1];

			nums[0] = temp;
		}
			

	}
};

Solution sol;

int main(void)
{
	/*
	Input: nums = [1,2,3,4,5,6,7], k = 3
	Output: [5,6,7,1,2,3,4]
	*/

	vector<int> vTest = { 1,2,3,4,5,6,7 };
	
	for (auto x : vTest)
		cout << x << ", ";
	cout << endl;

	sol.rotate(vTest,3);

	for (auto x : vTest)
		cout << x << ", ";
	cout << endl;

	return 0;
}