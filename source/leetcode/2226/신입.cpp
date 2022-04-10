typedef long long ll;

class Solution {
public:
    bool validPile(vector<int>& candies, int pile, ll k)
    {
        ll cnt = 0;
        
        for(int candy : candies) cnt += 1LL * candy / pile;
        return cnt >= k;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        int lo = 1, hi = 1e7;
        int ans = 0;
        
        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2;
            
            if(validPile(candies, mid, k))
            {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        
        return ans;
    }
};
