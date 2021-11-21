class Solution {
public:
    bool is_pal(const string& s) {
        for(auto i = 0; i < s.size() / 2; ++i)
            if(s[i] != s[s.size() - 1 - i])
                return false;
        
        return true;
    }
    
    string to_string_k_base(int k, long long num) {
        string ret;
        while(num) {
            ret.push_back(num % k);
            num /= k;
        }
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
    
    long long kMirror(int k, int n) {
        long long ret = 0;
        for(auto len = 1; n; ++len) {
            if(len == 1) {
                for(auto i = 1; n && i <= 9; ++i)
                    if(is_pal(to_string_k_base(k, i)))
                        ret += i, --n;
            } else {
                long long start = pow(10, len / 2 - 1);
                long long end = pow(10, len / 2);
                
                for(auto i = start; n && i < end; ++i) {
                    auto s = to_string(i);
                    auto r = s;
                    reverse(r.begin(), r.end());
                    
                    if(len % 2) {
                        for(auto c = '0'; n && c <= '9'; ++c) {
                            auto num = stoll(s + c + r);
                            auto k_base_str = to_string_k_base(k, num);
                            if(is_pal(k_base_str))
                                ret += num, --n;
                        }
                    } else {
                        auto num = stoll(s + r);
                        auto k_base_str = to_string_k_base(k, num);
                        if(is_pal(k_base_str))
                            ret += num, --n;
                    }
                }
            }
        }
        
        return ret;
    }
};
