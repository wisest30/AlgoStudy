typedef long long ll;

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.push_back(INT_MAX);
        
        ll ans = 0;
        
        int before = 0;
        
        for(int num : nums)
        {
            if(num == before+1 || num == before) 
            {
                before = num;
                continue;
            }
            
            int lo = before+1;
            int hi = min(before+k,num-1);
            int cnt = hi-lo+1;
            
            ans += 1LL * (hi + lo) * cnt / 2;
            k -= cnt;
            before = num;
        }
        
        return ans;
    }
};
