class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        
        auto check = [&](auto m) {
            if(workers.size() < m)
                return false;
            
            multiset<int> s(tasks.begin(), tasks.begin() + m);
            int cnt = pills;
            for(auto i = (int)workers.size() - m; i < workers.size(); ++i) {
                auto v = workers[i];
                auto p = s.upper_bound(v);
                if(p == s.begin()) {
                    if(cnt == 0) return false;
                    cnt--;
                    
                    p = s.upper_bound(v + strength);
                    if(p == s.begin()) return false;
                    s.erase(prev(p));
                } else {
                    s.erase(prev(p));
                }
            }
            
            return true;
        };
        
        int l = 0, r = tasks.size() + 1;
        while(l + 1 < r) {
            auto m = (l + r) / 2;
            if(check(m)) l = m;
            else r = m;
        }
        
        return l;
    }
};
