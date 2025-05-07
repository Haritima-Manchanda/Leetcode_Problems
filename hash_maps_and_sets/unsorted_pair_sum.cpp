/*

    Problem Statement: 
        You are given an unsorted array of integers and a target sum. 
        Your task is to determine whether any two distinct elements in the array add up to the target sum.

        You need to return: true if such a pair exists, false otherwise

        Examples:
            Input: nums = {10, 15, 3, 7}, target = 17
            Output: true

            Input: nums = {1, 2, 3, 9}, target = 8
            Output: false

*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool hasPairSorted(const vector<int> &nums, int target){

    unordered_set<int> hashset;

    for(int i = 0; i < nums.size(); i++){
        if(hashset.count(target - nums.at(i))){
            return true;
        }

        hashset.insert(nums.at(i));
    }

    return false;
}

int main(){

    vector<int> nums = {10, 15, 3, 7};
    int target = 17;

    // Use std::boolalpha to print true/false instead of 1/0
    cout<< boolalpha << hasPairSorted(nums, target)<< endl;

    nums = {1, 2, 3, 9};
    target = 8;

    cout<< boolalpha << hasPairSorted(nums, target)<< endl; 

    return 0;

}