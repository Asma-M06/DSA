/*
Approach : 2-pointer
variables : n ,sum , left , right
data structure: array/vector

steps:
1.Take sorted array and target from user
2.in the array :
    do:
        --left = 0 , right = array.size()-1 , result
        -- while left < right:
            --- sum = left + right
            --- check :
              ---- if target == sum
                ----- push indices to result
                -----left++
                -----right--
                ----- while left < right and left == left-1 : left++
                ----- while left < right and right == right+1 : right--
            --- if target < sum : right --
            else if target > sum : left ++
    return left and right

testcases:
[1,2,3,4,5] target = 3 ===>> output: 1,2
[3,4,5,6,7,8] target = 10 ===>> output: {1,5},{2,4}
*/
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > sumPairs(vector<int> &items, int target)
{
    vector<pair<int, int> > result;
    int sum = 0, left = 0, right = items.size() - 1;
    while (left < right)
    {
        sum = items[left] + items[right];
        if (sum == target)
        {
            result.push_back(make_pair(items[left], items[right]));
            left++;
            right--;

            while (left < right && items[left] == items[left - 1])
            {
                left++;
            }
            while (left < right && items[right] == items[right + 1])
            {
                right--;
            }
        }
        else if (target > sum){left++;}
        else {right--;}
    }
    return result;
}

int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    vector<int> item(n);
    cout << "Enter the elements in sorted order : ";
    for (int i = 0; i < n; i++)
    {
        cin >> item[i];
    }
    int target;
    cout << "Enter the target : ";
    cin >> target;
    vector<pair<int, int> > result = sumPairs(item, target);
    for(int i =0 ; i < result.size() ; i++){
        cout<<"{"<<result[i].first<<","<<result[i].second<<"} ";
    }
    return 0;
}