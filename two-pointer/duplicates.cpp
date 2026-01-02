/*
Approach : 2-pointer
variables : n, fast, slow
data structure : array/vector

steps:
1.Take user inputted sorted array
2.duplicates(arr,n):
    --slow = 0 , fast = 1
    -- traverse into array from 1 to n :
        --- if array[fast]!=array[slow]:
            ---- slow++
            ---- array[slow]=array[fast]
    return slow+1 that is length of array
3.print the unique array

Testcases:
[1,1,3,3,4,4] ===> [1,3,4]
[1,1,1,1,1] ====> [1]
[1,2,3,4] ===> [1,2,3,4]
*/

// code:
#include <iostream>
#include <vector>
using namespace std;
int duplicates(vector<int> &arr, int n)
{
    int slow = 0, fast;
    for ( fast = 1; fast < n; fast++){
        if(arr[fast]!=arr[slow]){
            slow ++ ;
            arr[slow] = arr[fast];
        }
    }
    return slow + 1;
}
int main()
{
    vector<int> arr;
    int n, x;
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << "Enter the elements in sorted order: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    int dup = duplicates(arr, n);
    for (int i = 0; i < dup; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}