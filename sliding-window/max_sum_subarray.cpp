/*
Approach : sliding window
variables: sum , maxsum , k , n , window variable : i
data structure: array/vector

steps:
1.take user inputted array size and elements and k (subarray size)
2.take sum of first k elements and maxSum = sum
3.loop from i = k to n-1:
    -- sum -= arr[i-k]  //remove leftmost
    -- sum += arr[i]   //add rightmost
    -- update maxSum if sum>maxSum
return maxSum

testcases:
[2,1,5,1,3,2], k = 3  -> 9
[1,2,3,4,5], k = 2    -> 9
[5,5,5,5], k = 2      -> 10

*/
// code:
#include <iostream>
#include <vector>
using namespace std;
int max_sum_subarray(vector<int> &arr, int k, int n)
{
    int sum=0;
    int maxStart = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    int maxSum = sum;
    for(int i = k ; i < n ; i++ )
    {
        sum -= arr[i-k];
        sum+= arr[i];
        if(sum > maxSum)
        {
            maxSum = sum;
            maxStart = i - k + 1;
            
        }
    }
     cout << "Max sum subarray: [ ";
    for (int i = maxStart; i < maxStart + k; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
    return maxSum;
}
int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cout << "Enter the size of subarray(k) : ";
    cin >> k;
    int result = max_sum_subarray(arr, k, n);
    cout<<"Maximum subarray sum is : "<<result<<" ";
    return 0;
}