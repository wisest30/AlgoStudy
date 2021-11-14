class Solution {
public:
    typedef long long ll;
    
    int n;
    vector<int> quantities;
    
    bool isValid(ll border)
    {
        vector<int> temp = quantities;
        
        int cur = 0;
        
        for(int i=0;i<n;i++)
        {
            if(cur == quantities.size()) break;
            temp[cur] -= min(border, (ll)temp[cur]);
            if(!temp[cur]) cur++;
        }
        
        return cur == quantities.size();
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        this->n = n;
        this->quantities = quantities;
        
        ll hi = 0;
        ll lo = 0;
        
        for(int quantity : quantities)
        {
            hi = max(hi, (ll)quantity);
            lo += quantity;
        }
        
        if(lo%n) lo = lo/n+1;
        else lo = lo/n;
        
        int ans = -1;
        
        while(lo <= hi)
        {
            ll mid = lo + (hi-lo)/2;
            
            if(isValid(mid)) 
            {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        
        return ans;
    }
};
