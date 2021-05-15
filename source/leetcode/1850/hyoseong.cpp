class Solution {
public:
    void next(string& num) {
        int i = -1;
        
        for(i = (int)num.size() - 2; i >= 0; --i) {
            if(num[i+1] > num[i])
                break;
        }
               
        char small_val = CHAR_MAX;
        int small_idx = -1;
        for(auto j = (int)num.size() - 1; j > i; --j) {
            if(num[j] > num[i] && num[j] < small_val) {
                small_val = num[j];
                small_idx = j;
            }
        }
        
        swap(num[i], num[small_idx]);
        sort(num.begin() + i + 1, num.end());
    }
    
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
            next(num);
        auto t = num;

        return swap_count(s, t);
    }
};
