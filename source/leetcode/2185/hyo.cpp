class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ret = 0;
        for(auto& s : words) ret += s.find(pref) == 0;
        return ret;
    }
};
