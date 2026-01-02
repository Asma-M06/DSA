/*
Approach : 2-pointer
variables : left, right
data structure : array

steps:
1.take user inputted array size and elements
2.use 2-pointer template:
    -- left = 0 , right = n-1
    -- check whether
        ---s[left] != s[right] return false
        ---after loop ends return true

testcases:
abba - true
aba - false
1221 - true
123 - false
*/

//code:
#include<iostream>
using namespace std;

bool isPal(string str){
    int length = str.length();
    int left = 0 , right = length - 1;
    while(left < right)
    {
        if(str[left] != str[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);


    if(isPal(str))
    {
        cout<<"The string "<<str<< " is palindrome ";
    }
    else
    {
        cout<<"The string "<<str<< " is not palindrome ";
    }
    return 0;
}