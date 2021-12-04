typedef long long ll;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<ll> ans(nums.size(), -1);
        ll total = 0;
        
        if(2*k+1 > nums.size()) return vector<int>(nums.size(), -1);
        
        for(int i=0;i<=2*k;i++) total += nums[i];
        
        for(int i=k;i+k<nums.size();i++)
        {
            ans[i] = total/(2*k+1);
            total -= nums[i-k];
            if(i+k+1 < nums.size()) total += nums[i+k+1];
        }
        
        vector<int> ansToInt;
        
        for(ll num : ans) ansToInt.push_back(num);
        
        return ansToInt;
    }
};
