#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

/*
Given a string s, reverse the order of characters in each word within
a sentence while still preserving whitespace and initial word order.
*/

class Solution {

	// Did not used
	void reverseString(string& s)
	{
		for (int li = 0, ri = s.size() - 1; li < ri; ++li, --ri)
		{
			char temp = s[li];
			s[li] = s[ri];
			s[ri] = temp;
		}
	}

public:
	string reverseWords(string s)
	{
		string result = s;
		
		// iterate over range [0,n]
		for (int i = 0, li = 0; i <= result.size(); ++i)
		{
			// seacrh for space or null termination
			if (result[i] == ' ' || result[i] == '\0')
			{
				// two pointer inverse over the word range
				for (int ri = i - 1; li < ri; ++li, --ri)
				{
					char temp = result[li];
					result[li] = result[ri];
					result[ri] = temp;
				}

				// left index points to the next word
				li = i + 1;
			}	
		}

		return result;
	}
};

Solution sol;

int main(void)
{
	/*
	Input: s = "Let's take LeetCode contest"
	Output: "s'teL ekat edoCteeL tsetnoc"
	*/

	string sTest = "Let's take LeetCode contest";
	string sResult = sol.reverseWords(sTest);

	cout << sTest << endl;
	cout << sResult << endl;

	return 0;
}