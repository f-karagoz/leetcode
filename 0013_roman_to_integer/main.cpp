#include "string"
#include "stdio.h"
using namespace std;

#define MAX_ROMAN_SIZE 15

/**
 * @todo
 * Seperate entered sting into chars
 * Weight check for special cases
 * Group the parts and calculate
 * 
*/

typedef enum
{
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000
    //E
}roman;

class Solution {
public:
    int romanToInt(string s) {

        int result = 0;
        roman romanArr[MAX_ROMAN_SIZE];

        string_to_roman(s, romanArr);

        for (int i = s.length()-1; i > -1; i--)
        {
            if (i != 0 && romanArr[i] <= romanArr[i - 1]) // generally expected
            {
                result += romanArr[i];
            }
            else if (i != 0) // special case, combine
            { 
                result += (romanArr[i] - romanArr[i-1]);
                i--;
            }
            else // i is 0
                result += romanArr[i];
        }

        return result;
    }

    int string_to_roman(string s, roman r[])
    {
        for (int i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
            case 'I':
                r[i] = I;
                break;
            case 'V':
                r[i] = V;
                break;
            case 'X':
                r[i] = X;
                break;
            case 'L':
                r[i] = L;
                break;
            case 'C':
                r[i] = C;
                break;
            case 'D':
                r[i] = D;
                break;
            case 'M':
                r[i] = M;
                break;
            default:
                //test1_arr[i] = E;
                break;
            }
        }

        return 1;
    }
};

Solution sol;

int main(void)
{
    string test_1 = "III";
    string test_2 = "LVIII";
    string test_3 = "MCMXCIV";

    printf("For %s we get %d.\n", test_1.c_str(), sol.romanToInt(test_1));
    printf("For %s we get %d.\n", test_2.c_str(), sol.romanToInt(test_2));
    printf("For %s we get %d.\n", test_3.c_str(), sol.romanToInt(test_3));

    return 0;
}
