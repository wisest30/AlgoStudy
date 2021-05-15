class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {        
        sort(intervals.begin(), intervals.end(), [](auto& l, auto& r) {
            return l[1] - l[0] < r[1] - r[0];
        });
        
        set<int> s;
        for(auto q : queries)
            s.insert(q);

        unordered_map<int, int> m;
        for(auto& i : intervals) {
            auto p = s.lower_bound(i[0]);
            auto q = s.upper_bound(i[1]);
            for(auto it = p; it != q; ++it)
                m[*it] = i[1] - i[0] + 1;

            s.erase(p, q);
        }
        
        vector<int> ret;
        for(auto q : queries)
            ret.push_back(m.count(q) ? m[q] : -1);
        
        return ret;
    }
};
