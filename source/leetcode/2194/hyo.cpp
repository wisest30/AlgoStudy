class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ret;
        for(auto c = s[0]; c <= s[3]; ++c)
            for(auto r = s[1]; r <= s[4]; ++r)
                ret.push_back(string(1, c) + string(1, r));
        
        return ret;
    }
};
