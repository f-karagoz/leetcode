/**
*   File:   main.c
*   Title:  Leetcode problem #383 Ransom Note
*   Author: Furkan Karagoz
*   Date:   5 September 2022
*/

#include "string"
#include "stdio.h"
#include "iostream" // used for testing with string outputs
using namespace std;

/*
* TODO
* Go though the elements of ransomNote
* For each element check if we have it in magazine
* If we have it go to the next element of the ransomNote
*   and mark (store) the id of the element of the magazine we have used
* When checking inside the magazine discard those ids
* 
*/

/***********************    THE TASK   **********************/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unsigned short charsFound = 0;

        unsigned short* usedIds;
        usedIds = (unsigned short*)malloc(magazine.length()*2); // unsigned short is has 2*string sizes

        if (usedIds == NULL)
            return 0;

        for (int i = 0; i < ransomNote.length(); i++)   // ransomeNote loop
        {
            for (int j = 0; j < magazine.length(); j++) // magazine loop
            {
                if (ransomNote[i] == magazine[j]) // Found it
                {
                    bool idUsed = false;

                    for (int k = 0; k < charsFound; k++) // Check if we found it before
                    {
                        if (j == usedIds[k]) // Id is used before
                        {
                            idUsed = true;
                        }
                    }

                    if (idUsed)
                        continue;
                    else
                    {
                        usedIds[charsFound] = j;
                        charsFound++;
                        break;  // break from the magazine loop
                    }
                }
                else
                {
                    if (j == magazine.length() - 1) // Last step, search failed for ransomeNote[i]
                    {
                        free(usedIds);
                        return 0;
                    }
                    else
                        continue; // continue searching, it will anyways
                }
            }
        }

        free(usedIds);
        return 1;
    }
};

/***********************    TESTS   **********************/

Solution solution;

void test(string ransom, string mag); // Declaration

int main(void)
{
    const int TEST_LENGTH = 8;

    string n[TEST_LENGTH] =
    {
        "abcd",
        "a",
        "aa",
        "aa",
        "aabbccddee",
        "aa",
        "aaa",
        "aaa"
    };
    string m[TEST_LENGTH] =
    {
        "123",
        "bc",
        "ab",
        "aab",
        "aaebbbeeccccdd",
        "ba",
        "baa",
        "bba"
    };

    for (int i = 0; i < TEST_LENGTH; i++)
    {
        test(n[i], m[i]);
    }
    
    /*
    string str = "ab\0";
    unsigned short us = 1;
    int i = 1;

    cout << "Size of\n" << "string : " << sizeof(str) << "\nunsigned short : " << sizeof(us) << "\nint : " << sizeof(i) << endl;
    */

    return 0;
}

void test(string ransom, string mag)
{
    cout << "For ransom " << ransom << " and mag " << mag << " we get : " << solution.canConstruct(ransom,mag) << "\n";
}