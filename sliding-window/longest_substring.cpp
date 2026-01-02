/*
Approach : sliding window
variables: maxlen , l , r
data structure: vector

steps:
1.take user inputted string and initialize n as string length
2.Initialize maxlen = 0 , l=0 , r =0
3.Initialize a vector freq(256,0)
4.Loop r from 0 to n-1:
    -- include string[right] i.e freq[string[right]]++
    --check if(freq[string[right]] > 1) //that means repeating char
        --shrink left:
            ---while(freq[string[right]] > 1):
            ---freq[string[left]]--
            ---left++
        maxlen = right - left +1
return maxlen

testcases:
"abcabcbb" → 3
"bbbbb" → 1
"pwwkew" → 3
"dvdf" → 3
" " → 1
"" → 0
"au" → 2
*/
// code:
#include <iostream>
#include <vector>
using namespace std;
int longest_substr(string str)
{
    int l = 0, maxLen = 0, n = str.size();
    vector<int> freq(256, 0);
    for (int r = 0; r < n ; r++)
    {
        freq[str[r]]++;
        if(freq[str[r]] > 1){
            while(freq[str[r]] > 1){
                freq[str[l]]--;
                l++;
            }
        
        }
        maxLen = max(maxLen,r - l +1);

    }
    return maxLen;

}
int main()
{
    int n;
    string str;
    cout << "Enter the string : ";
    getline(cin,str);

    int result = longest_substr(str);
    cout << "Unique substring length : " << result << " ";
    return 0;
}