/*

Problem Statement: 
    Given an array of integers return all triplets [a, b, c] such that a + b + c = 0
    The solution must not contain duplicate triplets (eg [1,2,3] and [3,2,1] are considered duplicate triplets)

    If no such triplets are found, return empty array.
    Each triplet can be arranged in any order, and the output can be returned in any order.

    Example:
        Input: nums = [0, -1, 2, -3, 1]
        Output: [[-1, 1, 0], [-3, 1, 2]]

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> find_triplets_sorted(vector<int> &nums){
    vector<vector<int>> result;

    sort(nums.begin(), nums.end()); // sort the input vector -> [-3, -1, 0, 1, 2]

    int left, right;
    int n = nums.size();
    int current_sum = 0;

    for(int i=0; i < n - 2; i++){
        if (nums.at(i) > 0){
            // if the vector is sorted and the first element is a positive integer, 
            // then all elements following it must be positive. 
            // Therefore, we cannot have a combination (a+b+c = 0), because for such 
            // a combination to exist, we need negative integers.
            break;   
        }

        if(i > 0 && nums.at(i) == nums.at(i-1)){
            // In order to avoid duplicate values.
            // If nums = [-4, -4, 1, 3]
            // Then we have [[-4, 1, 3], [-4, 1, 3]] , which are duplicate triplets.
            continue;
        }

        left = i + 1;
        right = n - 1;

        while(left < right){
            current_sum = nums[i] + nums[left] + nums[right];

            if(current_sum == 0){
                result.insert(result.end(), {nums[i], nums[left], nums[right]});

                left ++;

                while(left < right && nums[left] == nums[left - 1]){
                    left ++;
                }

                right --;
            }

            else if(current_sum < 0){
                left++;
            }

            else{
                right--;
            }
        }
    }

    return result;
}

int main(){

    vector<int> nums = {0, -11};

    vector<vector<int>> result = find_triplets_sorted(nums);

    for(const auto &row: result){
        cout << "[";
        for(const auto &num: row){
            cout<< num <<", ";
        }
        cout <<"]";
    }
    return 0;
}