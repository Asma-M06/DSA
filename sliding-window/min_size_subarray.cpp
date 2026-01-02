    #include <iostream>
#include <vector>
using namespace std;
 #define INF INT_MAX

 int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, sub_len = INF, l = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (sum >= target) {
                sub_len = min(sub_len, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        if (sub_len == INF)
            return 0;
        return sub_len;
    }


int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cout << "Enter the target : ";
    cin >> k;
    int result = minSubArrayLen(k, nums);
    cout<<"Minimum subarray sum is : "<<result<<" ";
    return 0;
}