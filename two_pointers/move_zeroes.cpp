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

void move_zeroes_staged_two_pointers(vector<int> &nums){
    // Using staged 2 pointers

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

void move_zeroes_unidirectional_two_pointers(vector<int> &nums){
    int left = 0;

    for(int right= 0; right < nums.size(); right++){
        if(nums[right] != 0){
            nums[left] = nums[right];
            left += 1;
        }
    }

    while(left < nums.size()){
        nums[left] = 0;
        left +=1;
    }
}

int main(){

    vector<int> nums = {0, 1, 0, 3, 12};
    move_zeroes_unidirectional_two_pointers(nums);

    cout<<"After move_zeroes, nums = ";

    for(int x: nums){
        cout<<x <<", ";
    }
    cout<<endl;

    nums = {0, 0, 1};
    move_zeroes_unidirectional_two_pointers(nums);

    cout<<"After move_zeroes, nums = ";

    for(int x: nums){
        cout<<x <<", ";
    }
    cout<<endl;


    return 0;
}