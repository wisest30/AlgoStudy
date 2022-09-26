class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> o(names.size());
        iota(o.begin(), o.end(), 0);
        sort(o.begin(), o.end(), [&](auto l, auto r) { return heights[l] > heights[r]; });
        
        vector<string> ret;
        for(auto i : o) ret.push_back(names[i]);
        
        return ret;
    }
};