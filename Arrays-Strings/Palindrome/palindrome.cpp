/*
Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
*/
#include<iostream>
using namespace std;
bool IsChar(const char& ch){
    if( (ch >= 'a' && ch <= 'z') || ((ch >= 'A' && ch <= 'Z'))|| (ch >= '0' && ch <= '9'))
        return true;
    return false;
}

bool IsPalindromeString(string s){
    int i =0, j = s.length()-1;

    while(i<j){
        while(i<j && !IsChar(s[i])) i++;
        while(i<j && !IsChar(s[j])) j--;
        if(tolower(s[i]) == tolower(s[j])){
            i++;
            j--;
        } else {
            return false;
        }
    }
    return true;
}

int main(){
    string s = "A man, a plan, a canal: Panama";
    cout<<IsPalindromeString(s)<<endl;
}