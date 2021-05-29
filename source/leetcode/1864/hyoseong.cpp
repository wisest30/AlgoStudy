class Solution {
public:
    int swap_cnt(const string& s, const string& t) {
        pair<int, int> p;
        for(auto i = 0; i < s.size(); ++i)
            if(s[i] != t[i]) s[i] == '0' ? p.first++ : p.second++;
        
        if(p.first == p.second) return p.first;
        else return INT_MAX;
    }

    int minSwaps(string s) {
        int n = s.size();
        string t0, t1;
        for(auto i = 0; i < n; ++i) {
            if(i % 2 == 0) t0.push_back('0'), t1.push_back('1');
            else t0.push_back('1'), t1.push_back('0');
        }
        
        auto ret = min(swap_cnt(s, t0), swap_cnt(s, t1));
        if(ret == INT_MAX) ret = -1;
        return ret;
    }
};
