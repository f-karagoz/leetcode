#include <iostream>
using namespace std;

class Solution
{
public:
	int bulbSwitch(int n)
	{
		int* bulbs = (int*)calloc(n, sizeof(int));
		int res = 0;

		for (int i = 1; i <= n; ++i)
		{
			for (int j = i-1; j < n; j += i)
				bulbs[j] = !bulbs[j];
		}

		// count
		for (int i = 0; i < n; ++i)
			if (bulbs[i] == 1)
				res++;

		return res;
	}
};

Solution sol;

int main(void)
{
	sol.bulbSwitch(1);

	cout << "hello" << endl;
	return 0;
}