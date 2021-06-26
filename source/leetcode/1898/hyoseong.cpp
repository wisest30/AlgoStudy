class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {        
        auto check = [&](auto m) {
            auto cloneS = s;
            for(auto i = 0; i < m; ++i)
                cloneS[removable[i]] = 0;

            int i = 0, j = 0;
            for(; i < cloneS.size() && j < p.size(); ++i)
                if(cloneS[i] == p[j])
                    ++j;
            
            return j == p.size();
        };
        
        int l = 0, r = removable.size() + 1;
        while(l + 1 < r) {
            auto m = (l + r) / 2;
            if(check(m))
                l = m;
            else
                r = m;
        }
        
        return l;
    }
};
