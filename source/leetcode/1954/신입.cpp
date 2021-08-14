class Solution {
public:
    typedef long long ll;
    
    ll getRes(ll num)
    {
        return 2*num*(num+1)*(2*num+1);
    }
    
    long long minimumPerimeter(long long neededApples) {
        ll mn = 1;
        ll mx = 1'00000;
        
        ll ans = -1;
        
        while(mn <= mx)
        {
            ll mid = mn + (mx-mn)/2;
            
            if(getRes(mid) >= neededApples)
            {
                ans = mid;
                mx = mid-1;
            }
            else mn = mid+1;
        }
        
        return 8*ans;
    }
};
