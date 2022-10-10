#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int search(vector<int>& nums, int target)
	{
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] == target)
				return i;

		return -1;
	}
};

Solution sol;

int main(void)
{
	vector<int> vTest = {-1,0,3,5,9,12};
	sol.search(vTest, 1);

	cout << "hello" << endl;
	return 0;
}