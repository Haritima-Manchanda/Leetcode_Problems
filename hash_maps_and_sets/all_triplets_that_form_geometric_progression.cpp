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
#include <unordered_set>
using namespace std;

vector<vector<int>> find_all_triplets_of_geometric_progression(const vector<int> nums){
    vector<vector<int>> result;
    unordered_set<int> set(nums.begin(), nums.end());

    int num_j, num_i, num_k;

    for(int j=1; j < nums.size(); j++){
        num_j = nums[j];

        for(int i=0; i < j; i++){
            num_i = nums[i];
            num_k = (num_j * num_j) / num_i;

            if((num_j * num_j) % num_i == 0 && set.find(num_k) != set.end() && num_k > num_j){
                result.push_back({num_i, num_j, num_k});
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