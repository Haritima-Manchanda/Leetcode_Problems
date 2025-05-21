/*
    Problem Statement: 
    Determine if a number is happy number or not.

    A happy number is a number defined by the following process: 
        Starting with any positive integer, replace the number by the sum of the squares of its digits, 
        and repeat the process until the number equals 1 (where it will stay), or it loops endlessly 
        in a cycle that does not include 1. If a number is a happy number, then all members 
        of its sequence are happy numbers.

        
*/

#include <iostream>
using namespace std;

int get_new_num(int num){

    int sum_of_squares = 0;
    int digit_squared;

    while(num > 0){
        digit_squared = (num % 10) * (num % 10);
        sum_of_squares = sum_of_squares + digit_squared;
        num = num / 10;
    }

    return sum_of_squares;
}

bool is_happy_number(int n){
    int fast = get_new_num(n), slow = n;

    while(fast != 1 && fast != slow){
        cout<< "Fast "<< fast << " Slow "<< slow <<endl;
        fast = get_new_num(get_new_num(fast));
        slow = get_new_num(slow);
    }

    return fast == 1;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (is_happy_number(num))
        cout << num << " is a Happy Number!" << endl;
    else
        cout << num << " is NOT a Happy Number!" << endl;

    return 0;
}