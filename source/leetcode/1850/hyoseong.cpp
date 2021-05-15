class Solution {
public:    
    int swap_count(string s, string t) {
        int ret = 0;
        int n = s.size();
        for(auto i = 0; i < n; ++i) {            
            auto p = find(s.begin() + i, s.end(), t[i]) - s.begin();
            ret += p - i;
            for(auto j = p; j > i; --j)
                swap(s[j], s[j-1]);
        }
        
        return ret;
    }
    
    int getMinSwaps(string num, int k) {
        auto s = num;
        for(auto i = 0; i < k; ++i)
            next_permutation(num.begin(), num.end());
        auto t = num;

        return swap_count(s, t);
    }
};
