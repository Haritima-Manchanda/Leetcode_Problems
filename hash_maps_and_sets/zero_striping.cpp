/*

    Problem Statement: 
        For each zero in a (m x n) matrix, set its entire row and column to zero in place.
        
    Examples:
        Input: 
            [[1, 0, 1],
             [1, 1, 1],
             [1, 1, 0]
            ]

        Output: 
            [[0, 0, 0],
             [1, 0, 0],
             [0, 0, 0]
            ]


        Input: [
            [0, 1, 2, 0],
            [3, 4, 5, 2],
            [1, 3, 1, 5]
            ] 
        
        Output: [
            [0, 0, 0, 0],
            [0, 4, 5, 0],
            [0, 3, 1, 0]
            ]
*/


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void zero_striping_with_inplace_zero_tracking(vector<vector<int>> &matrix){
    if(matrix.empty() || matrix[0].empty()){
        return;
    }

    int m = matrix.size();
    int n = matrix[0].size();

    bool firstRowHasZero = false, firstColHasZero = false;

    for(int j=0; j < n; j++){
        if(matrix[0][j] == 0){
            firstRowHasZero = true;
            break;
        }
    }

    for(int i=0; i < m; i++){
        if(matrix[i][0] == 0){
            firstColHasZero = true;
            break;
        }
    }

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[0][j] == 0 || matrix[i][0] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    if(firstRowHasZero){
        for(int j = 0; j < n; j++){
            matrix[0][j] = 0;
        }
    }

    if(firstColHasZero){
        for(int i = 0; i < m; i++){
            matrix[i][0] = 0;
        }
    }
}

void zero_striping(vector<vector<int>> &matrix){

    if(matrix.empty() || matrix[0].empty()){
        return;
    }

    int m = matrix.size();
    int n = matrix[0].size();

    unordered_set<int> rows;
    unordered_set<int> cols;

    for(int i=0; i < m; i++){
        for(int j=0; j < n; j++){
            if(matrix[i][j] == 0){
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    for(int i=0; i < m; i++){
        for(int j=0; j < n; j++){
            if(rows.count(i) || cols.count(j)){
                matrix[i][j] = 0;
            }
        }
    }


}

int main(){

    vector<vector<int>> matrix = {{1, 0, 1}, {1, 1, 1}, {1, 1, 0}};

    zero_striping(matrix);

    cout<< "Matrix after zero striping" << endl;
    for(const auto& row : matrix){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    matrix = {{0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}};
    zero_striping(matrix);

    cout<< "Matrix after zero striping" << endl;
    for(const auto& row : matrix){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    matrix = {{0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}};

    zero_striping_with_inplace_zero_tracking(matrix);

    cout<< "Matrix after in place zero striping" << endl;
    for(const auto& row : matrix){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}

