class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        auto check = [&](auto m) {
            long long su = 0;
            for(auto t : time) {
                su += m / t;
                if(su >= totalTrips)
                    return true;
            }
            return false;
        };
        
        long long l = 0, r = 1e15;
        while(l + 1 < r) {
            auto m = (l + r) / 2;
            check(m) ? r = m : l = m;
        }
        
        return r;
    }
};
