#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
Given two strings s1 and s2, return true
if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations
is the substring of s2.
*/

/*
Approach:
Make an hash-map for count of all the characters in s1
Slide a window over s1 and lower the character number if encountered
When all the characters in the has-map reach zero permutation is found
*/

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        // hashmap for frequency of all character in s1
        unordered_map<char, int>mp;
        for (auto it : s1)
            mp[it]++;

        // check that if all the characters in the map
        // have the same frequency, indicating anagram found
        int count = mp.size();
        int i = 0, j = 0;
        int k = s1.size();          // window size

        while (j < s2.size())
        {
            // if a ch is found in map, reduce its freq
            if (mp.find(s2[j]) != mp.end())
            {
                mp[s2[j]]--;
                // if freq of the specific ch is zero
                // all occurances of ch is found 
                // in the current window
                if (mp[s2[j]] == 0)
                    count--;
            }

            if (j - i + 1 < k)
            {
                j++;
            }
            else if (j - i + 1 == k)
            {
                // anagram found
                if (count == 0)
                    return true;
                
                // Check if that character is present
                // in the map while sliding the window,
                // then increase its frequency by one,
                // as we decreased its frequency when we
                // first met it while crossing the window.
                if (mp.find(s2[i]) != mp.end())
                {
                    mp[s2[i]]++;

                    if (mp[s2[i]] == 1)
                        count++;
                }
                i++;
                j++;
            }
        }
        return false;
    }
};

Solution sol;

int main(void)
{
    cout << "hi" << endl;

    return 0;
}