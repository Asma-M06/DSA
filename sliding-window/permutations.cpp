/*
Approach : sliding window
variables:l,r,window_len,window_now,str1,str2
data structure: vector/array


steps:
1.Take user inputted strings : str1 , str2
----check for empty string and return false
2.Buid freq1 for str1
3.initialize window_len to str1.len and iniatialize freq2 for str2 and window_now=0
l=0
4.loop r=0 to str2.length():
   --freq2[str[r]]++;
   --window_now++;
   --if(window_now == window_len) //that means we have chararcters length same as str1
            ----if(freq1==freq2)
                ----- return true //there exist permutation
        ---else //shrink the window from l
            ----freq[str2[l]]--;
            ----l++;



testcases:
*/
// code:
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define INF INT_MAX
bool permutations_str(string str1, string str2)
{
    if (str2.empty() || str1.empty())
    {
        return false;
    }
    if(str1.length() > str2.length())
    {
        return false;
    }
    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);

    for (unsigned char c : str1)
    {
        freq1[c-'a']++;
    }

    int l = 0;
    
    for (int r = 0; r < str2.size(); r++)
    {
        unsigned char c1 = str2[r];
        freq2[c1-'a']++;
        
        if(r - l + 1 > str1.length()){
            unsigned char c2 = str2[l];
            freq2[c2 - 'a']--;
            l++;
            
        }
        if (r - l + 1 == str1.length())
        {
            if (freq1 == freq2)
            {
                return true;
            }  
        }
       
    }
    return false;
}
int main()
{
    string s, t;
    cout << "Enter the main string: ";
    getline(cin, s);
    cout << "Enter the substring: ";
    getline(cin, t);
    bool result = permutations_str(t, s);
    if (result)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}