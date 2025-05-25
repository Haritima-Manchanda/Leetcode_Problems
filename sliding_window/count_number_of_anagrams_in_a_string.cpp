/*
    Problem Statement:
        Given two strings, s and t, find the number of substrings in s that are anagrams of string t.

        An anagram of a string is a rearrangement of its characters. For example, the anagrams of "abc" are "abc", "acb", "bac", "bca", "cab", and "cba".

        Your task is to count how many substrings of length equal to t in s are anagrams of t.

        Input:
        A string s representing the main string.

        A string t representing the target anagram string.

        Output:
        An integer representing the count of anagram substrings of t found in s.

        Constraints:
        0 <= s.length(), t.length() <= 10^5

        Strings s and t consist of ASCII characters.


        Input:
            s = "cbaebabacd"
            t = "abc"

            Output:
            2

            Explanation:
            The anagrams of "abc" found in s are "cba" (substring s[0..2]) and "bac" (substring s[6..8]).

        Input:
            s = "abcdefg"
            t = "hij"

            Output:
            0

            Explanation:
            No anagrams of "hij" appear in the string "abcdefg".


*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <cassert>
using namespace std;


int count_number_of_anagrams(const string &s, const string &t){
    if(t == "" || s == "" || t.size() > s.size()){
        return 0;
    }

    int count_anagrams = 0;
    int window_size = t.size();
    int left = 0;

    unordered_map<char, int> t_char_freq_map; // to store character frequency in string t
    unordered_map<char, int> current_window_map; // to store character frequency in current window of string s

    for(char c : t){
        t_char_freq_map[c]++;
    }

    int count_char = t_char_freq_map.size(); // Number of distint characters in the anagram

    for(int right = 0; right < s.size(); right++){

        if(current_window_map.find(s[right]) != current_window_map.end()){
            current_window_map[s[right]]++;
        }
        else{
            current_window_map[s[right]] = 1;
        }


        if(right - left + 1 == window_size){
            if(current_window_map == t_char_freq_map){
                count_anagrams += 1;
            }
            current_window_map[s[left]]--;
            if(current_window_map[s[left]] == 0){
                current_window_map.erase(s[left]);
            }
            left++;
        }
    }

    return count_anagrams;
}


int main() {
    // Basic cases
    assert(count_number_of_anagrams("cbaebabacd", "abc") == 2); // "cba", "bac"
    assert(count_number_of_anagrams("abab", "ab") == 3);         // "ab", "ba", "ab"

    // Edge cases
    assert(count_number_of_anagrams("", "a") == 0);
    assert(count_number_of_anagrams("a", "") == 0);
    assert(count_number_of_anagrams("", "") == 0);
    assert(count_number_of_anagrams("a", "aa") == 0); // t is longer than s

    // No matches
    assert(count_number_of_anagrams("abcdefg", "hij") == 0);

    // Repeating characters
    assert(count_number_of_anagrams("aaaaa", "aa") == 4); // "aa" appears at [0,1], [1,2], [2,3], [3,4]

    // Entire string is an anagram
    assert(count_number_of_anagrams("abc", "bca") == 1); // "abc" is an anagram of "bca"

    // Case sensitivity check
    assert(count_number_of_anagrams("aAbBc", "Ab") == 1); // Only "Ab" matches

    cout << "All test cases passed!\n";
    return 0;
}