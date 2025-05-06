/*

Problem Statement:
    Given an array of integers sorted in ascending order and a target value, 
    return the indexes of any pair of numbers in the array that sum to the target.

    The order of the indexes does not matter in the result. 
    If no pair is found, return an empty array.

    Example 1: 
        Input: nums = [-5, -2, 3, 4, 6] target = 7
        Output = [2, 3]

        Explanation: nums[2] + nums[3] = 3 + 4 = 7


    Example 2: 
    Input: nums = [1, 1, 1], target = 2
    Output = [0, 1]

    Explanation: other valid inputs could be [1, 0], [0, 2], [2, 0], [1, 2] or [2, 1]

*/


#include <vector>
#include <iostream>

using namespace std;

vector<int> find_pair_sorted(const vector<int> &nums, int target){
    vector<int> result;

    if(nums.size() < 2){
        return result;
    }

    int i = 0, j = nums.size() - 1;
    int current_sum = 0;

    while(i < j){
        current_sum = nums.at(i) + nums.at(j);

        if(current_sum < target){
            i += 1;
        }
        else if(current_sum > target){
            j -= 1;
        }
        else {
            // current_sum == target
            result.push_back(i);
            result.push_back(j);
            break;
        }
    }

    return result;
}

int main(){
    vector<int> nums = {-5, -2, 3, 4, 6};
    int target = 7;

    vector<int> result = find_pair_sorted(nums, target);

    for(auto x: result){
        cout<< x << ", ";
    }
    cout<<endl;

    // Test Case 1 and 2: Test an empty array and test an array with just one element
    nums = {};
    target = 0;
    result = find_pair_sorted(nums, target);

    for(auto x: result){
        cout<< x << ", ";
    }
    cout<<endl;

    nums = {1};
    target = 1;
    result = find_pair_sorted(nums, target);

    for(auto x: result){
        cout<< x << ", ";
    }
    cout<<endl;

    // Test a two element array that contains a pair that sums to the target
    nums = {2, 3};
    target = 5;

    result = find_pair_sorted(nums, target);

    for(auto x: result){
        cout<< x << ", ";
    }
    cout<<endl;

    // Test an array with duplciate values
    nums = {2, 2, 3};
    target = 5;

    result = find_pair_sorted(nums, target);

    for(auto x: result){
        cout<< x << ", ";
    }
    cout<<endl;

    // Test if the algorithm works with a negative number in the target pair
    nums = {-1, 2, 3};
    target = 2;

    result = find_pair_sorted(nums, target);

    for(auto x: result){
        cout<< x << ", ";
    }
    cout<<endl;

    // Test if the target works with both numbers of the target pair being negative
    nums = {-3, -2, -1};
    target = -5;

    result = find_pair_sorted(nums, target);

    for(auto x: result){
        cout<< x << ", ";
    }
    cout<<endl;


    return 0;
}