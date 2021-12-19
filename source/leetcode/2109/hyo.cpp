class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ret;
        for(int i = 0, j = 0; i < s.size(); ++i) {
            if(j < spaces.size() && i == spaces[j])
                ret.push_back(' '), ++j;
            ret.push_back(s[i]);
        }
        
        return ret;
    }
};
