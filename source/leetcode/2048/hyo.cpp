class Solution {
public:
    int nextBeautifulNumber(int n) {
        int ret = n+1;
        while(true) {
            auto s = to_string(ret);
            int cnt[10] = {0};
            for(auto c : s)
                cnt[c - '0']++;
            
            bool valid = true;
            if(cnt[0]) valid = false;
            for(auto i = 0; i < 10; ++i)
                if(cnt[i] && cnt[i] != i)
                    valid = false;
            
            if(valid)
                break;
            ++ret;
        }
        
        return ret;
    }
};
