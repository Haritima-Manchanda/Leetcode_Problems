/*
    Problem Statement: 
        You are given an array representing the heights of trees, and an integer k representing the total length
        of wood that needs to be cut. 

        For this task a wood cutting machine is set to a certain height, H. The machine cuts the top part
        of all trees taller than H, while trees shorter than H remain untouched. Determine the highest 
        possible setting of the woodcutter (H) so that it cuts atleast k meters of wood. 

        Assume the woodcutter cannot be set higher than the height of the tallest tree in the array. 

        Example: 
            Inputs: heights = [2, 6, 3, 8] , k = 7
            Output = 3

            Explanation: The highest possible height setting that yields at least k = 7 meters of wood is 3, which
            yields 8 meters of wood. Aby height setting higher than this will yield less than 7 meters of wood. 

        Constraints: 
            1. Its always possible to attain at least k meters of wood. 
            2. There's atleast one tree.
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

bool can_achieve_atleast_k(const vector<int> &heights, int H, int k){
    int amount_of_total_wood_that_can_be_cut = 0;

    for(int height: heights){
        if (H < height){
            amount_of_total_wood_that_can_be_cut += height - H;
        }
    }
    return amount_of_total_wood_that_can_be_cut >= k; 
}

int find_last_occurrence(const vector<int> &heights, int k){
    int low = 0, high = *max_element(heights.begin(), heights.end());
    int result = -1, mid;

    while(low <= high){
        mid = low + (high - low) / 2;

        if(can_achieve_atleast_k(heights, mid, k)){
            result = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    vector<int> heights1 = {2, 6, 3, 8};
    int k1 = 7;
    assert(find_last_occurrence(heights1, k1) == 3);

    vector<int> heights2 = {5, 7, 9, 15};
    int k2 = 10;
    assert(find_last_occurrence(heights2, k2) == 7);

    vector<int> heights3 = {20, 15, 10, 17};
    int k3 = 7;
    assert(find_last_occurrence(heights3, k3) == 15);

    vector<int> heights4 = {4, 42, 40, 26, 46};
    int k4 = 20;
    assert(find_last_occurrence(heights4, k4) == 36);

    vector<int> heights5 = {10};
    int k5 = 3;
    assert(find_last_occurrence(heights5, k5) == 7);

    cout << "All test cases passed successfully!" << endl;
    return 0;
}