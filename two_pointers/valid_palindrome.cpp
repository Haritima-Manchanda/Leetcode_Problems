/*
    Problem Statement:
        Given a strubg s, determine if its a palindrome, considering only alphanumeric characters and ignoring cases.

        Example 1: 
            Input: s = "A man, a plan, a canal: Panama"
            Output: true  
            Explanation: "amanaplanacanalpanama" is a palindrome."

        Example 2:
            Input: s = "race a car"
            Output: false  
            Explanation: "raceacar" is not a palindrome.

        Example 3:
            Input: s = ""
            Output: true
            Explanation: An empty string is always a palindrome.
*/

#include <iostream>
#include <string>
#include<cctype>

using namespace std;

bool is_valid_palindrome(const string &s){
    int left = 0, right = s.size() - 1;

    while(left < right){

        while(left < right && !isalnum(s.at(left))){
            left++;
        }

        while(left < right && !isalnum(s.at(right))){
            right--;
        }
        if(tolower(s.at(left)) != tolower(s.at(right))){
            return false;
        }
        left++;
        right--;
    }

    return true;

}

int main(){

    string s = "A man, a plan, a canal: Panama";
    cout<<"Is \""<<s<<"\""<<" a palindrome: "<<is_valid_palindrome(s)<< endl;

    s = "23";
    cout<<"Is \""<<s<<"\""<<" a palindrome: "<<is_valid_palindrome(s)<< endl;

    s = "race a car";
    cout<<"Is \""<<s<<"\""<<" a palindrome: "<<is_valid_palindrome(s)<< endl;
    return 0;
}