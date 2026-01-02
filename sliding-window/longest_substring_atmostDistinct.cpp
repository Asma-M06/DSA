/*
Approach : sliding window
variables: maxlen , l , r , distinct ,
data structure: vector

steps:
1.take user inputted string and initialize n as string length and take k as number of distinct characters
2.Initialize maxlen = 0 , l=0 , r =0 ,distinct = 0
3.Initialize a vector freq(256,0)
4.Loop r from 0 to n-1:
    -- include string[right] i.e freq[string[right]]++
    --check if(freq[string[right]] == 1) //that means distinct char
    --distinct++
    while(distinct > k):
        --shrink left:
        ---freq[string[left]]--
        ---if(freq[string[left]] == 0):
            ---left++
            --distinct--
    --maxlen = max(maxlen,right - left +1)
return maxlen

testcases: for k=2
"abcabcbb" → 3
"bbbbb" → 5
"pwwkew" → 3
"dvdf" → 3
" " → 1
"" → 0
"au" → 2
*/
// code:
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int longest_substr(string str, int k)
{
    int start = 0;
    int l = 0, maxLen = 0, n = str.size(), distinct = 0;
    vector<int> freq(256, 0);
    for (int r = 0; r < n; r++)
    {
        unsigned char char1 = (unsigned char)str[r];
        freq[char1]++;

        if (freq[char1] == 1)
        {
            distinct++;
        }
        while (distinct > k)
        {
            unsigned char char2 = (unsigned char)str[l];
            freq[char2]--;
            if (freq[char2] == 0) // removed 1 distinct from leftmost
            {
                distinct--;
            }
            l++;
        }
        if (maxLen < r - l + 1)
        {
            maxLen = r - l + 1;
            start = l;
        }
    }
    cout << "Substring with " << k << " distincts : " << str.substr(start, maxLen) << "\n";
    return maxLen;
}
int main()
{
    int n, k;
    string str;
    cout << "Enter the string : ";
    getline(cin, str);
    cout << "Enter k number of distincts: ";
    cin >> k;
    int result = longest_substr(str, k);
    cout << "substring length : " << result << " ";
    return 0;
}