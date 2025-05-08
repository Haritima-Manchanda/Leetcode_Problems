/*
    Problem Statements:
        Given a sorted array of distinct positive integers, print all triplets that 
        forms Geometric Progression with integral common ratio.
        A geometric progression is a sequence of numbers where each term after 
        the first is found by multiplying the previous one by a fixed, non-zero number called the common ratio. 
        For example, the sequence 2, 6, 18, 54,… is a geometric progression with common ratio 3.

    Examples: 
        Input: 
        arr = [1, 2, 6, 10, 18, 54]
        Output: 
        2 6 18
        6 18 54

        Input: 
        arr = [2, 8, 10, 15, 16, 30, 32, 64]
        Output: 
        2 8 32
        8 16 32
        16 32 64

        Input: 
        arr = [ 1, 2, 6, 18, 36, 54]
        Output: 
        2 6 18
        1 6 36
        6 18 54
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> find_all_triplets_of_geometric_progression(const vector<int> nums){
    vector<vector<int>> result;
    int n = nums.size();
    int i, k;

    for(int j = 1; j < n; j++){
        i = j - 1; 
        k = j + 1;

        while(i >= 0 && i < j && k < n){
            if(nums[j] * nums[j] == nums[i] * nums[k]){
                result.push_back({nums[i], nums[j], nums[k]});
                i--;
                k++;
            }
            else if(nums[j] * nums[j] < nums[i] * nums[k]){
                i--;
            }
            else{
                k++;
            }
        }
    }
    return result;
}

int main() {
    vector<int> arr = {2, 8, 10, 15, 16, 30, 32, 64};
    vector<vector<int>> triplets = find_all_triplets_of_geometric_progression(arr);

    for (const auto& triplet : triplets) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}