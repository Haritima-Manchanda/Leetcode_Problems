/*
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
    You must write an algorithm that runs in O(n) time.

    Example 1:
        Input: nums = [100,4,200,1,3,2]
        Output: 4
        Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
        Example 2:

        Input: nums = [0,3,7,2,5,8,4,6,0,1]
        Output: 9
        Example 3:

        Input: nums = [1,0,1,2]
        Output: 3
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int longest_chain_of_consequtive_numbers(vector<int> nums){ //100,4,200,1,3,2
    unordered_set<int> hashset(nums.begin(), nums.end());
    int longest_seq = 0, current_num, current_length;

    for(int num: hashset){
        if(!hashset.count(num-1)){
            current_num = num;
            current_length = 1;

            while(hashset.count(current_num + 1)){
                current_num += 1;
                current_length += 1;
            }
            longest_seq = max(longest_seq, current_length);
        }
    }
    return longest_seq;
}

int main(){
    vector<int> nums = {100,4,200,1,3,2};
    int length = longest_chain_of_consequtive_numbers(nums);
    cout<< length;
    return 0;
}