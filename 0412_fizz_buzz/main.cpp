#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<string> fizzBuzz(int n)
	{
		vector<string> result;

		for (int i = 1; i < n+1; i++)
			if (i % 15 == 0)
				result.push_back("FizzBuzz");
			else if (i % 3 == 0)
				result.push_back("Fizz");
			else if (i % 5 == 0)
				result.push_back("Buzz");
			else
				result.push_back( to_string(i) );

		return result;
	}
};

Solution solution;

int main(void)
{
	vector<string> test = solution.fizzBuzz(30);

	for (auto i = test.begin(); i != test.end(); i++)
		cout << *i << " ";

	cout << endl;

	return 0;
}