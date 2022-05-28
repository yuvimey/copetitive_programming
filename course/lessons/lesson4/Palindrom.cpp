//
// Created by Gili on 03/01/2022.
//

//O(n) functions to check if a string is a palindrome

#include <string>
#include <xstring>

using namespace std;

bool isPalindrome(string s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        if(s[start] != s[end])
        {
            return false;
        }
        start++, end--;
    }
    return true;
}

bool isPalindromeUsingReverse(string s)
{
    string s_tmp = s;
    reverse(s.begin(), s.end());
    return s_tmp == s;
}