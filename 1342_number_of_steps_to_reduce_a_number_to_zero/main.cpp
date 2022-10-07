#include <iostream>
using namespace std;

class Solution
{
public:
	int numberOfSteps(int num)
	{
		int stepCounter = 0;

		while (num != 0)
		{
			if (num % 2)
				num--;
			else
				num /= 2;
			stepCounter++;
		}

		return stepCounter;
	}
};

Solution solution;

int main(void)
{
	int number = 14;

	cout << "Number of steps required for " << number <<
		" is " << solution.numberOfSteps(number) << endl;

	return 0;
}