class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        auto ret = s;
        for(auto i = 0; i < s.size(); ++i) {
            ret[indices[i]] = s[i];
        }
        return ret;
    }
};
