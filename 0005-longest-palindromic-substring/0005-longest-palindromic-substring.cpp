#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int expandFromMiddle(string s, int start, int end) {
        int left = start, right = end;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
    string longestPalindrome(string s) {
        if(s.length()==0){
            return "";
        }
        if(s.length()==1){
            return s;
        }  
        int start = 0;
        int end = 0;
        for(int i=0;i<s.length();i++){
            int len1 = expandFromMiddle(s,i,i);
            int len2 = expandFromMiddle(s,i,i+1);
            int len = max(len1,len2);
            if(len>end-start){
                start = i-(len-1)/2;
                end = i+(len)/2;
            }

        }
        return s.substr(start,end-start+1);
    }
};