/*
Approach : sliding window
variables:l,r,window_len,window_now,str1,str2
data structure: vector/array


steps:
1.Take user inputted strings : str1(substring) , str2(mainstring)
2.Buid freq1 for str1
Buid a result vector
3.loop r=0 to str2.length():
   --freq2[str[r]]++;
   --if(r-l+1 == str1.len()):
        ---if freq1 == freq2
        ---result.push_back(l)
   --if(r-l+1 > str1.len()):
        ---shrink
        ---freq[str2[l]]--;
        ---l++;
return result



testcases:
*/
// code:
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> anagram_str(string str1, string str2)
{
    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);
    vector<int> result;
    for (unsigned char c : str1)
    {
        freq1[c - 'a']++;
    }

    int l = 0;

    for (int r = 0; r < str2.size(); r++)
    {
        unsigned char c1 = str2[r];
        freq2[c1 - 'a']++;

        if (r - l + 1 > str1.length())
        {
            unsigned char c2 = str2[l];
            freq2[c2 - 'a']--;
            l++;
        }
        if (r - l + 1 == str1.length())
        {
            if (freq1 == freq2)
            {
                result.push_back(l);
            }
        }
    }
    return result;
}
int main()
{
    string s, t;
    cout << "Enter the main string: ";
    getline(cin, s);
    cout << "Enter the substring: ";
    getline(cin, t);
    vector<int> result = anagram_str(t, s);
    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout<< result[i]<<",";
    }
    cout << "]";
    return 0;
}