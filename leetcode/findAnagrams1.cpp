//
// Created by Ahsan Ghani on 2022-08-06.
//
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> goal(26);
        vector<int> current(26);
        vector<int> result;
        for(char c : p)
        {
            goal[c-'a']++;
        }
        for(int i=0; i<s.size(); i++)
        {
            current[s[i]-'a']++;
            if(i>=p.size())
            {
                current[s[i-p.size()]-'a']--;
            }
            if(current==goal)
            {
                result.push_back(i-p.size()+1);
            }
        }
        return result;
    }
};