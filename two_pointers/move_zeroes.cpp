/*

    Problem Statement: 
        Given an array of integers, move all the 0s to the end of the array while maintaining the relative order of the non-zero elements. The operation should be done in-place with minimal extra space.

        This problem could also be stated as:
            Move all negative numbers to the left.

        Example 1:
            Input: nums = [0, 1, 0, 3, 12]

            Output: [1, 3, 12, 0, 0]

        
        Example 2:
            Input: nums = [0, 0, 1]

            Output: [1, 0, 0]
*/

#include <iostream>
#include <vector>

using namespace std;

void move_zeroes(vector<int> &nums){
    // Using unidirectional 2 pointers

    int left = 0;
    int temp;
    
    for(int right = 0; right < nums.size(); right++){
        if(nums[right] != 0){
            temp = nums[right];
            nums[right] = nums[left];
            nums[left] = temp;

            left += 1;
        }
    }
}

int main(){

    vector<int> nums = {0, 1, 0, 3, 12};
    move_zeroes(nums);

    cout<<"After move_zeroes, nums = ";

    for(int x: nums){
        cout<<x <<", ";
    }
    cout<<endl;

    nums = {0, 0, 1};
    move_zeroes(nums);

    cout<<"After move_zeroes, nums = ";

    for(int x: nums){
        cout<<x <<", ";
    }
    cout<<endl;


    return 0;
}