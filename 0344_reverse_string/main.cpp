#include <iostream>
#include <vector>
using namespace std;

/*
Write a function that reverses a string.
The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.
*/

class Solution {
public:
	void reverseString(vector<char>& s)
	{

	}
};

Solution sol;

int main(void)
{
	/*
	* Input: s = ["h","e","l","l","o"]
	Output: ["o","l","l","e","h"]
	*/

	vector<char> vTest = { 'h','e','l','l','o' };

	for (auto x : vTest)
		cout << x << ", ";
	cout << endl;

	sol.reverseString(vTest);

	for (auto x : vTest)
		cout << x << ", ";
	cout << endl;

	return 0;
}