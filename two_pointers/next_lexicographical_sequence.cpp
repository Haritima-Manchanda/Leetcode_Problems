/*
    Problem Statement:
        Given an array of integers nums, rearrage it into the lexicographically next greater permutation of numbers.
        If such an arrangement is not possible (i.e. the array is sorted in descending order), rearrange it as the 
        lowest possible order (i.e. sorted in ascending order) 

        Example: 
            Input: nums = [1, 2, 3]
            Output: [1, 3, 2]

            Input: nums = [3, 2, 1]
            Output: [1, 2, 3]

            Input: nums = [1, 3, 5, 4, 2]
            Output: [1, 4, 2, 3, 5]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> next_permutation_lexicographically(vector<int> nums){

    int n = nums.size();  // [1, 3, 5, 4, 2], n = 5
    int i = n - 2;

    while(i >= 0 && nums[i] >= nums[i+1]){
        i--;  // i = 1, nums[i] = 3
    }

    if(i >= 0){
        int j = n - 1;
        while(j >= i && nums[j] <= nums[i]){
            j--; // j=3, nums[j] = 4
        }


        // Swap
        swap(nums[i], nums[j]); // [1, 4, 5, 3, 2]


        // Reverse
        reverse(nums.begin() + i + 1, nums.end());
    }

    else {
        reverse(nums.begin(), nums.end());
    }

    return nums;

}

int main() {
    vector<vector<int>> test_cases = {
        {1, 2, 3},
        {3, 2, 1},
        {1, 1, 5},
        {2, 3, 1},
        {1},
        {1, 2},
        {2, 1}
    };

    for (auto& test : test_cases) {
        vector<int> result = next_permutation_lexicographically(test);
        for (int num : result)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}