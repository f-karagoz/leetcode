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
		// shrinking the range from left and right

		vector<int> result;
		int li = 0;
		int ri = numbers.size() - 1;

		while (li != ri)
		{
			if (numbers[li] + numbers[ri] == target)
				break;
			else if (numbers[li] + numbers[ri] > target)
				ri--;
			else
				li++;
		}

		if (li == ri)	// Not found case
			return vector<int>({ -1,-1 });

		return vector<int>({ li + 1, ri + 1 });
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