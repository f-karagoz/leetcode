#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s, int windowSize = 1, int longestSize = 0)
    {
        string window;

        for (int i = 0; i < s.size() - 1; i++)
        {
            
            window.push_back(s[i]);

            cout << window << endl;

            int duplicate_found = 0;

            for (int j = 0; j < window.size(); j++)
                if (s[i + 1] == window[j])
                    duplicate_found = 1;

            if (!duplicate_found)
            {
                windowSize++;
            }
                
            else
            {
                window.clear();
                
                if (windowSize > longestSize)
                    longestSize = windowSize;

                windowSize = 0;
            }

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