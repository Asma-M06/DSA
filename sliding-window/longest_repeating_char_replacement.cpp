/*
Approach : sliding window
variables:l,r,str,k,max_freq
data structure: vector/array


steps:
1.Take user inputted strings : str and number of attempts to change char: k
2.initialize l=0 , max_freq=0 ,best=0
3.loop r through str:
    freq[str[r]]++;
    maxfreq=max(maxfreq,freq[str[r]]);
    if(r-l+1 > k ):
        -freq[str[l]]--
        -l++
    best=max(r-l+1,max_freq)



testcases:
Input: s = "ABAB", k = 2
Output: 4
Input: s = "AABABBA", k = 1
Output: 4

*/
// code:
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int charReplacement(string str, int k)
{

    int l = 0, max_freq = 0, best = 0,window=0;
    vector<int> freq(26, 0);
    for (int r = 0; r < str.size(); r++)
    {
        unsigned char character = str[r];
        freq[character - 'A']++;
        max_freq = max(max_freq, freq[character-'A']);
        window=r-l+1;
        if (window - max_freq > k)
        {
            unsigned char ch = str[l];
            freq[ch - 'A']--;
            l++;
        }
        best = max(best, r-l+1);
    }
    return best;
}

int main()
{
    string str;
    int k;
    cout << "Enter the string: ";
    getline(cin, str);
    cout << "Enter k attempts : ";
    cin >> k;
    cout << charReplacement(str, k);
    return 0;
}