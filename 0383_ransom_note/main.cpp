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
        unsigned short ransomNoteCount[26] = { 0 };
        unsigned short magazineCount[26] = { 0 };

        for (int i = 0; i < ransomNote.length(); i++)
            ransomNoteCount[ransomNote[i] - 97]++;

        for (int i = 0; i < magazine.length(); i++)
            magazineCount[magazine[i] - 97]++;

        for (int i = 0; i < 26; i++)
            if (magazineCount[i] - ransomNoteCount[i] < 0) return 0;

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