/*
Approach : sliding window
variables: required , l, r, matchCount , start ,length_str,bestLen
data structure: vector/array
                -- need[],have[]

steps:
1.take user inputted strings - s and t
2.min_wun_substring(s,t):
-return "" if t is empty
    -initialize l =0 ,r =0,n=s.length(),bestLen=INF,length_str=0
    -build need[],required for t //char we need to match with s
    -build have[] for s //char we have in s
    -loop from r=0 to r=n-1:
        --c=s[r]
        --have[c]++
        -- if (have[c] < = need[c]) : matchCount++
        --while (matchCount == required):
            ---length_str = r-l+1
            ---if(bestLen > length_str)
                ----bestLen = length_str
                ----start = l
            ---have[s[l]]--
            ---if(have[s[l]]<need[s[l]]):matchCount--
            ---l++

-if(bestLen == INF) return""
return s.substr(start,bestLen);

testcases: for k=2
s = "ADOBECODEBANC", t = "ABC"   → "BANC"
s = "a", t = "a"                 → "a"
s = "a", t = "aa"                → ""
s = "ab", t = "b"                → "b"
s = "aa", t = "aa"               → "aa"

*/
// code:
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define INF INT_MAX
string min_window_substring(string s, string t)
{
    if (t.length() == 0)
        return "";
    int l = 0, bestLen = INF, start = 0, matchCount = 0, required = 0;
    vector<int> need(256, 0);
    vector<int> have(256, 0);
    for (unsigned char c : t)
    {
        need[c]++;
        required++;
    }
   

    for (int r = 0; r < s.length(); r++)
    {
        unsigned char char1 = (unsigned char)s[r];
        have[char1]++;
        if (have[char1] <= need[char1])
        {
            matchCount++;
        }

        while (matchCount == required)
        {
            int length_str = r - l + 1;
            if (bestLen > length_str)
            {
                bestLen = length_str;
                start = l;
            }
            unsigned char char2 = (unsigned char)s[l];
            have[char2]--;
            if (have[char2] < need[char2])
            {
                matchCount--;
            }
            l++;
        }
    }

    if (bestLen == INF)
        return "";

    return s.substr(start, bestLen);
}
int main()
{
    string s, t;
    cout << "Enter the main string: ";
    getline(cin, s);
    cout << "Enter the substring: ";
    getline(cin, t);
    string result = min_window_substring(s, t);
    cout << "The minimum substring is: " << result;
    return 0;
}