class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        auto ret = vector<int>{first};
        for(auto e : encoded)
            ret.push_back(ret.back() ^ e);
        
        return ret;
    }
};
