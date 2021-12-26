class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<long long>> m;
        for(auto i = 0; i < n; ++i)
            m[arr[i]].push_back(i);
        
        vector<long long> ret(n);
        for(auto& p : m) {
            long long rs = accumulate(p.second.begin(), p.second.end(), 0ll);
            long long ls = 0, rc = p.second.size(), lc = 0;
            for(auto i = 0; i < p.second.size(); ++i) {
                rs -= p.second[i], --rc;
                ret[p.second[i]] = rs - p.second[i] * rc + p.second[i] * lc - ls;
                ls += p.second[i], ++lc;
            }
        }
        
        return ret;
    }
};
