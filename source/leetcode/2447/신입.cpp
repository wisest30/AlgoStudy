class Solution {
public:
    int getGCD(int a, int b)
    {
        if(a%b == 0) return b;
        return getGCD(b, a%b);
    }
    
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            int gcd = nums[i];
            
            if(gcd == k) ans++;
            
            for(int j=i+1;j<n;j++)
            {
                gcd = getGCD(gcd, nums[j]);
                if(gcd == k) ans++;
                else if(gcd < k) break;
            }
        }
        
        return ans;
    }
};
