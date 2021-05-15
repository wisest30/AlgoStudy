class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        set<int> s;
        for(auto q : queries)
            s.insert(q);
        
        sort(intervals.begin(), intervals.end(), [](auto& l, auto& r) {
            return l[1] - l[0] < r[1] - r[0];
        });
        
        unordered_map<int, int> m;
        for(auto& i : intervals) {
            auto p = s.lower_bound(i[0]);
            auto q = s.upper_bound(i[1]);
            for(auto it = p; it != q; ++it)
                m[*it] = i[1] - i[0] + 1;

            s.erase(p, q);
        }
        
        vector<int> ret;
        for(auto q : queries) {
            if(m.count(q))
                ret.push_back(m[q]);
            else
                ret.push_back(-1);
        }
        
        return ret;
    }
};
