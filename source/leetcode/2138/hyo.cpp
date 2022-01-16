class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        while(s.size() % k) s.push_back(fill);
        vector<string> ret(s.size() / k);
        for(auto i = 0; i < s.size(); ++i) ret[i / k].push_back(s[i]);
        return ret;
    }
};
