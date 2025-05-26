/*
    Problem Statement: 
        You are given a sorted array that contains unique values, along with an integer target. 

        1. If the array contains the target value, return its index. 
        2. Otherwise, return the insertion index. This is the index where the target would be if it were inserted in 
        order, maintaining the sorted sequence of the array.  

        Example 1: 
            nums = [1, 2, 4, 5, 7, 8, 9], target = 4
            Output = 2

        Example 2: 
            nums = [1, 2, 4, 5, 7, 8, 9], target = 6
            Output = 4
            Explanation: 6 would be inserted at index 4 to be positioned between 5 and 7: [1. 2. 4, 5, 6, 7, 8, 9]
*/

#include <iostream>
#include <vector>
#include <cassert> 

using namespace std;

int find_the_insertion_index(const vector<int> &nums, int target){
    int low = 0, high = nums.size() - 1;
    int mid;

    while(low <= high){
        mid = low + (high - mid) / 2;
        if (nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;

}

int main(){
    
    // Test case 1: target exists in the array
    vector<int> nums1 = {1, 2, 4, 5, 7, 8, 9};
    assert(find_the_insertion_index(nums1, 4) == 2);

    // Test case 2: target should be inserted in the middle
    assert(find_the_insertion_index(nums1, 6) == 4);

    // Test case 3: target should be inserted at the beginning
    assert(find_the_insertion_index(nums1, 0) == 0);

    // Test case 4: target should be inserted at the end
    assert(find_the_insertion_index(nums1, 10) == 7);

    // Test case 5: target is smaller than all elements
    vector<int> nums2 = {5, 10, 15};
    assert(find_the_insertion_index(nums2, 1) == 0);

    // Test case 6: empty array
    vector<int> nums3 = {};
    assert(find_the_insertion_index(nums3, 42) == 0);

    cout << "All test cases passed!" << endl;

    return 0;
}