typedef long long ll;
class Solution {
public:
    bool isValid(vector<int>& time, int totalTrips, ll target)
    {
        ll trips = 0;
        
        for(int& thisTime : time) trips += target/thisTime;
        if(trips >= totalTrips) return true;
        return false;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll lo = 0;
        ll hi = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;
        ll ans = -1;
        
        
        while(lo <= hi)
        {
            ll mid = lo + (hi-lo)/2;
            
            if(isValid(time, totalTrips, mid))
            {
                hi = mid - 1;
                ans = mid;
            }
            else lo = mid + 1;
        }
        
        return ans;
    }
};
