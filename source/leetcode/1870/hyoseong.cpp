class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour <= n-1) return -1;
        
        auto check = [&](long long m) {
            double t = 0;
            for(auto i = 0; i < n-1; ++i)
                t += (dist[i] + m - 1) / m;
            
            return t + (double)dist.back() / m <= hour;
        };
        
        long long l = 0, r = 1e7 + 1;
        while(l + 1 < r) {
            long long m = (l+r) / 2;
            if(check(m)) r = m;
            else l = m;
        }
        
        return r;
    }
};
