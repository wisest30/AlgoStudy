class Solution {
public:
    int minimumBuckets(string s) {
        int n = s.size();
        int ret = 0;
        for(auto i = 0; i < n; ++i) {
            if(s[i] == 'H') {
                if(i && s[i-1] == 'B') continue;
                if(i < n-1 && s[i+1] == '.') {
                    ++ret;
                    s[i+1] = 'B';
                    continue;
                } else if(i && s[i-1] == '.') {
                    ++ret;
                } else {
                    return -1;
                }
            }
        }
        
        return ret;
    }
};
