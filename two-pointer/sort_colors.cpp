/*
Approach : 3-pointer
variables :low(0) , mid(1) , high(2)
data structure : array/vector

steps:
1.Take user inputted array
2.sort_colors(arr,n):
    --low,mid = 0 , high = n- 1
    -- traverse into array while(mid<=high) :
        --- if array[mid]==0: swap array[low] and array[mid] ; mid++ low++
        --- else if array[mid]==1 : mid++
        --- else : swap array[mid] and array[high] high--
3.print the sorted array

Testcases:
[1,0,2,0,0,1] ===> [0,0,0,1,1,2]
[0,1,1,0,1,2] ====> [0,0,1,1,1,2]
[0,1,2] ===> [0,1,2]
*/

//code:
#include<iostream>
#include<vector>
using namespace std;
void sort_colors(vector<int> &arr , int n){
    int low=0, mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid] == 0)
        {
            swap(arr[low],arr[mid]);
            low ++ ;
            mid ++ ;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high --;
        }
    }
    
}
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin >> n;
    vector<int> arr;
    cout<<"Enter the colors(0s,1s,2s) : ";
    for(int i= 0 ;i <n ;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    sort_colors(arr,n);
    cout<<"\n sorted colors: \n";
    for(int i= 0 ;i <n ;i++)
    {
       cout<<arr[i]<<" ";
    }
    return 0;
}