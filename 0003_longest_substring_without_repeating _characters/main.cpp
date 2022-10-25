#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s, int longestSize = 0)
    {

        for (int li = 0, ri = 0; ri < s.size(); ++ri)
        {

            for (int i = li; i < ri; ++i)
                if (s[i] == s[ri]) // duplicate found
                    li = i + 1;

            if (ri - li + 1 > longestSize)
                longestSize = ri - li + 1;

        }

        return longestSize;
    }
};

Solution sol;

int main(void)
{
    cout << "hi" << endl;
    /*
    Input: s = "abcabcbb"
    Output: 3
    */

    string sTest = "pwwkew";

    cout << "Longest substring size is: " << sol.lengthOfLongestSubstring(sTest) << endl;

    return 0;
}