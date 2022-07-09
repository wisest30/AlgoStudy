class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& b, vector<int>& p, int c) {
        sort(b.begin(), b.end());
        sort(p.begin(), p.end());
        
        auto check = [&](auto m) {
            auto pp = p;
            while(!pp.empty() && pp.back() >= m)
                pp.pop_back();
            pp.push_back(m);
            
            int i = 0, j = 0, cur = 0;
            while(i < b.size() && j < pp.size()) {
                if(pp[j] <= b[i] && cur < c)
                    ++j, ++cur;
                else
                    ++i, cur = 0;
            }
            
            return j == pp.size();
        };
        
        int l = 0, r = b.back() + 1;
        while(l + 1 < r) {
            auto m = (l + r) / 2;
            if(check(m)) l = m;
            else r = m;
        }
        
        int ret = l;
        unordered_set<int> s(p.begin(), p.end());
        while(s.count(ret))
            --ret;
        
        return ret;
    }
};
