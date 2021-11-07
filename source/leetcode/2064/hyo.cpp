class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        auto check = [&](auto m) {
            int cnt = n;
            for(auto q: quantities) {
                while(cnt && q) {
                    --cnt;
                    q -= min(q, m);
                }
                
                if(cnt == 0 && q > 0)
                    return false;
            }
            
            return true;
        };
        
        int l = 0, r = 1e5 + 1;
        while(l + 1 < r) {
            auto m = (l + r) / 2;
            if(check(m)) r = m;
            else l = m;
        }
        
        return r;
    }
};
