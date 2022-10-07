#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumWealth(vector<vector<int>>& accounts)
	{
		int maximumWealth = 0;
		int customerWealth = 0;

		for (vector<int> vect1D : accounts)
		{
			for (int x : vect1D)
				customerWealth += x;

			if (customerWealth > maximumWealth)
				maximumWealth = customerWealth;

			customerWealth = 0;
		}


		return maximumWealth;
	}
};

Solution solution;

int main(void)
{
	vector<vector<int>> accounts =
	{
		{1,2,3},
		{4,5,6},
		{1,2,4}
	};

	cout << "Maximum wealth is : " << solution.maximumWealth(accounts) << endl;
	return 0;
}