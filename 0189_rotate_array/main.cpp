#include <iostream>
#include <vector>
using namespace std;

/*
Given an array, rotate the array to the right
by k steps, where k is non-negative.
*/

class Solution
{
	void inverse(vector<int>&nums, int il_, int ir_)
	{
		while (il_ < ir_)
		{
			int temp = nums[il_];
			nums[il_] = nums[ir_];
			nums[ir_] = temp;
			il_++;
			ir_--;
		}
	}
public:
	void rotate(vector<int>& nums, int k)
	{
		if (k == 0)
			return;
		else
			k = abs(k) % nums.size();

		inverse(nums, 0, nums.size() - k - 1);
		inverse(nums, nums.size() - k, nums.size() - 1);
		inverse(nums, 0, nums.size() - 1);
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
	
	cout << "Input array :" << endl;
	for (auto x : vTest)
		cout << x << ", ";
	cout << endl;

	sol.rotate(vTest,3);

	cout << "Rotated array :" << endl;
	for (auto x : vTest)
		cout << x << ", ";
	cout << endl;

	return 0;
}