//
// Created by Ahsan Ghani on 2022-08-05.
//
class Solution {
public:
    int numDecodings(string s) {
        return s.empty() ? 0: numDecodings(0,s);
    }
    int numDecodings(int p, string& s) {
        int n = s.size();
        if(p == n) return 1;
        if(s[p] == '0') return 0; // sub string starting with 0 is not a valid encoding
        int res = numDecodings(p+1,s);
        if( p < n-1 && (s[p]=='1'|| (s[p]=='2'&& s[p+1]<'7'))) res += numDecodings(p+2,s);
        return res;
    }
};