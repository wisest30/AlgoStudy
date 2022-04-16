typedef long long ll;

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int zeroCnt = 0;
        
        priority_queue<ll> pq;
        
        for(int num : nums)
        {
            pq.push(-1LL * num);
            if(num == 0) zeroCnt++;
        }
        
        while(k--)
        {
            ll cur = pq.top();
            pq.pop();
            
            if(cur == 0) zeroCnt--;
            pq.push(cur-1);
        }
        
        if(zeroCnt) return 0;
        
        ll ans = 1LL;
        
        while(!pq.empty())
        {
            ll cur = pq.top();
            pq.pop();
            
            ans = (ans * (-cur))%(1'000'000'007);
        }
        
        return ans;
    }
};
