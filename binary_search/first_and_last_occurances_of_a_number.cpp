/*
    Given an array of integers sorted in non-decreasing order, return the first and last indexes of a target number. 
    If the target is not found, return [-1. -1]

    Example 1: 
    Input: nums= [1. 2, 3, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11], target = 4 
    Output = [3, 5]

    Explanation: The first and last occurances of number 4 are indexes 3, and 5, respectively. 
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int find_first_occurrance(const vector<int> &nums, int target){
    int result = -1;
    int low = 0, high = nums.size() - 1;
    int mid;

    while(low <= high){
        mid = low + (high - low)/2;

        if(nums[mid] == target){
            result = mid;
            high = mid - 1; // Continue searching to the left
        }
        else if(nums[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return result;
}

int find_last_occurrance(const vector<int> &nums, int target){
    int result = -1;

    int low = 0, high = nums.size() - 1;
    int mid;

    while(low <= high){
        mid = low + (high - low)/2;

        if(nums[mid] == target){
            result = mid;
            low = mid + 1; // Continue searching to the right
        }
        else if(nums[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return result;
}

vector<int> find_first_and_last(const vector<int> &nums, int target) {
    return {find_first_occurrance(nums, target), find_last_occurrance(nums, target)};
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11};

    // Test 1: target = 4
    auto res = find_first_and_last(nums, 4);
    assert(res[0] == 3 && res[1] == 5);

    // Test 2: target = 1 (first element)
    res = find_first_and_last(nums, 1);
    assert(res[0] == 0 && res[1] == 0);

    // Test 3: target = 11 (last element)
    res = find_first_and_last(nums, 11);
    assert(res[0] == 12 && res[1] == 12);

    // Test 4: target = 6
    res = find_first_and_last(nums, 6);
    assert(res[0] == 7 && res[1] == 7);

    // Test 5: target not found
    res = find_first_and_last(nums, 100);
    assert(res[0] == -1 && res[1] == -1);

    cout << "All test cases passed successfully!" << endl;
    return 0;
}