/*
    Problem Statement: 
        Longest Substring Without Repeating Characters

        You are given a string s. Your task is to find the length of the longest substring of s that does not contain any repeating characters.

        A substring is a contiguous sequence of characters within a string.

        Example: s="abcdef", return 0 "abcdef"
        s = "abcabcbb", return 3 -> "abc"
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <cassert>

using namespace std;

int longest_substring_with_unique_characters(const string &s){
    int max_len = 0;
    unordered_set<char> set;
    int left = 0;

    for(int right = 0; right < s.size(); right++){
        if(set.find(s[right]) == set.end()){
            set.insert(s[right]);
        }
        else{
            //  max_len = max(max_len, set.size()); If this is done here, then it fails the case when s = "abcdef" that is all unique chars exist because this only gets executed when a duplicate is found.
            while(set.find(s[right]) != set.end()){
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
        }
        max_len = max(max_len, right - left + 1); 
    }
    return max_len;
}

int main() {
    // ✅ Basic cases
    assert(longest_substring_with_unique_characters("abcabcbb") == 3); // "abc"
    assert(longest_substring_with_unique_characters("bbbbb") == 1);    // "b"
    assert(longest_substring_with_unique_characters("pwwkew") == 3);   // "wke"

    // ✅ Edge cases
    assert(longest_substring_with_unique_characters("") == 0);         // Empty string
    assert(longest_substring_with_unique_characters("a") == 1);        // Single character
    assert(longest_substring_with_unique_characters("au") == 2);       // All unique

    // ✅ Edge case with no repeats (buggy version would fail)
    assert(longest_substring_with_unique_characters("abcdef") == 6);   // Entire string

    // ✅ All characters are different except one repeat
    assert(longest_substring_with_unique_characters("abcdafg") == 6);  // "bcda", "cdaf", "dafg"

    // ✅ All same characters
    assert(longest_substring_with_unique_characters("aaaaaa") == 1);   // Only one unique

    // ✅ Case sensitivity
    assert(longest_substring_with_unique_characters("AaBbCc") == 6);   // Case-sensitive

    cout << "All tests passed!" << endl;
    return 0;
}
