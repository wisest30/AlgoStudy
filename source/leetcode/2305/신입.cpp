class Solution {
public:
    int n;
    int k;
    vector<int> cookies;
    
    int ans;
    int bucket[10];
    
    void build(int idx)
    {
        if(idx == n)
        {
            int mx = INT_MIN;
            for(int i=0;i<k;i++) mx = max(mx, bucket[i]);
            ans = min(ans, mx);
            return;
        }
        
        for(int i=0;i<k;i++)
        {
            bucket[i] += cookies[idx];
            build(idx+1);
            bucket[i] -= cookies[idx];
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        this->k = k;
        this->cookies = cookies;
        
        ans = INT_MAX;
        
        build(0);
        
        return ans;
    }
};
