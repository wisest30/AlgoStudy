class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        reverse(s.begin(), s.end());
        
        auto val = [&](auto c) { return c - 'a' + 1; };
        long long h = 0, p = 1, idx = -1;
        for(auto i = 0; i < s.size(); ++i) {
            h = (h * power % modulo + val(s[i])) % modulo;
            if(i < k) p = p * power % modulo;
            else h = (h - p * val(s[i-k]) % modulo + modulo) % modulo;   
            if(i >= k - 1 && h == hashValue) idx = i - k + 1;
        }

        auto ret = s.substr(idx, k);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
