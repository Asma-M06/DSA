/*
Approach : 2-pointer
variables : n, fast, slow
data structure : array/vector

steps:
1.Take user inputted array
2.Move_zeroes(arr,n):
    --slow = 0 , fast = 0
    -- traverse into array from 1 to n :
        --- if array[fast]!=0:
            ---- swap array[slow] and array[fast]
            ----slow++;
3.print the array

Testcases:
[1,0,3,0,4,4] ===> [1,3,4,4,0,0]
[0,1,1,0,1] ====> [1,1,1,0,0]
[1,2,3,4] ===> [1,2,3,4]
*/

//code:
#include<iostream>
#include<vector>
using namespace std;
void move_zeroes(vector<int> &arr , int n){
    int slow=0;
    for(int fast = 0 ;fast <n ;fast++){
        if(arr[fast] != 0){
            swap(arr[slow],arr[fast]);
            slow++;
        }
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin >> n;
    vector<int> arr;
    cout<<"Enter the elements : ";
    for(int i= 0 ;i <n ;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    move_zeroes(arr,n);
    for(int i= 0 ;i <n ;i++)
    {
       cout<<arr[i]<<" ";
    }
    return 0;
}