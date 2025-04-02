/*
    Problem Statement:
        You are given an array height where height[i] represents the height of a vertical line at index i.
        Find two lines that, together with the x axis, form a container that holds the most water.
        Return the maximum amount of water a container can hold. 

        Example 1: 
            Input: height = [1,8,6,2,5,4,8,3,7]
                   index =  [0.1,2,3,4,5,6,7,8]
            Output: 49

            Explanation: The container is formed between indices 1 and 8 
            with a height of 7 and width of 7 (7 * 7 = 49).

        Example 2:
            Input: height = [1,1]  
            Output: 1  
            
            Explanation: The only possible container has a width of 1 and a height of 1 (1 * 1 = 1).
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> container_with_max_area(const vector<int> &height){
    int left = 0, right = height.size() - 1;
    int max_area = 0;
    int current_area = 0;
    vector<int> result;

    while(left < right){
        // area = width * minimum of height at left and right
        
        current_area = (right - left) * min(height.at(left), height.at(right));

        if (max_area < current_area){
            max_area = current_area;
            result = {left, right};
        }

        if(height.at(left) < height.at(right)){
            // We are taking a chance that moving to the right might increase the height.
            left++; 
        }

        else{
            // We are taking a chance that moving to the left might increase the height.
            right--;
        }
    }

    return result;
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    vector<int> result = container_with_max_area(height);

    cout<<"Container with max water is formed by the lines at indices: "<< result.at(0) << " and "<< result.at(1)<< endl;

    height = {1, 1};
    result = container_with_max_area(height);

    cout<<"Container with max water is formed by the lines at indices: "<< result.at(0) << " and "<< result.at(1)<< endl;

    return 0;
}