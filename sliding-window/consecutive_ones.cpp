/*
Approach : sliding window
variables:l,r,zero_counts,k
data structure: vector/array


steps:
1.Take user inputted array : arr and number of attempts to change : k
2.initialize l=0 , zero_count=0 ,best=0
3.loop r through array:
    if arr[r]==0 zero_count++;
    while(zero_count > k ):
        -zero_count--
        -l++
    best=max(r-l+1,best)



testcases:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10

*/
// code:
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int charReplacement(vector<int> &nums, int k)
{

    int l = 0, zero_count = 0, best = 0, window = 0;
    for (int r = 0; r < nums.size(); r++)
    {
        if (nums[r] == 0)
        {
            zero_count++;
        }
        while (zero_count > k)
        {

            if (nums[l] == 0)
                zero_count--;
            l++;
        }
        best = max(best, r - l + 1);
    }
    return best;
}

int main()
{
    vector<int> nums;
    int k, x, y;
    cout << "Enter the elements size: ";
    cin >> y;
    cout << "Enter elements: ";
    for (int i = 0; i < y; i++)
    {
        cin >> x;
        nums.push_back(x);
    }
    cout << "Enter k attempts : ";
    cin >> k;
    cout << charReplacement(nums, k);
    return 0;
}