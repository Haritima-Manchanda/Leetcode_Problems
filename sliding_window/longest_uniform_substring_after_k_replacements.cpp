/*
    Problem Statement:
    Longest Substring with Same Letters After Replacement

    Given a string s consisting of uppercase English letters and an integer k, you may replace at most k characters in the string so that all the characters in the resulting substring are the same.
    Your task is to find the length of the longest such substring you can obtain.

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

int longest_uniform_substring_after_k_replacements(const string &s, int k){
    vector<int> freq_map(26, 0);
    int max_len = 0, highest_freq = 0;

    int left = 0, number_of_elements_to_replace, window_size;

    for(int right = 0; right < s.size(); right++){
        freq_map[s[right] - 'A']++;

        highest_freq = *max_element(freq_map.begin(), freq_map.end()); // can also do: highest_freq = max(highest_freq, freq_map[s[right] - 'A']])
        window_size = right - left + 1;
        number_of_elements_to_replace = window_size - highest_freq;

        if(number_of_elements_to_replace > k){
            freq_map[s[left] - 'A']--;
            left++;
        }
        max_len = max(max_len, right - left + 1);
    }
    return max_len;
}

int main(){
    assert(longest_uniform_substring_after_k_replacements("ABAB", 2) == 4);
    assert(longest_uniform_substring_after_k_replacements("AABABBA", 1) == 4);
    assert(longest_uniform_substring_after_k_replacements("ABCDE", 1) == 2);
    assert(longest_uniform_substring_after_k_replacements("AAAA", 2) == 4);
    assert(longest_uniform_substring_after_k_replacements("BAAAB", 2) == 5);
    cout << "All test cases passed!" << endl;
    return 0;
}