#include <iostream>
#include <vector>
using namespace std;

/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
find two numbers such that they add up to a specific target number.
Let these two numbers be numbers[index1]and numbers[index2]
where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers, index1 and index2,
added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution.
You may not use the same element twice.
Your solution must use only constant extra space.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
	{
		// aproach:
		// we iterate over the range [1:n]
		// two poniters: li, ri
		// li starting from 0, compares values of ri

		vector<int> result;

		for (int li = 0, ri = 1; li < numbers.size(); ++li, ri = li + 1)
		{
			for (; ri < numbers.size(); ++ri)
			{
				if (numbers[li] + numbers[ri] == target)
				{
					result.push_back(li + 1);
					result.push_back(ri + 1);
					return result;				// found
				}
				else if (numbers[li] + numbers[ri] > target)
					break;
			}
					
		}

		// not found
		result.push_back(-1);
		result.push_back(-1);
		return result;

    }
};

Solution sol;

int main(void)
{
	/*
	Input: numbers = [2,7,11,15], target = 9
	Output: [1,2]
	*/
	vector<int> vTest = { 2,7,11,15 };

	for (auto x : vTest)
		cout << x << ", ";
	cout << endl;

	vector<int> vResult = sol.twoSum(vTest, 9);

	for (auto x : vResult)
		cout << x << ", ";
	cout << endl;

	return 0;
}