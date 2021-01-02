class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l=0;
        int cnt[1'0000+5]{};
        int notUniqueCnt=0;
        int sum=0;
        int ans=0;
        
        for(int r=0;r<nums.size();r++)
        {
            cnt[nums[r]]++;
            if(cnt[nums[r]] == 2) notUniqueCnt++;
            else if(cnt[nums[r]] == 1) sum += nums[r];
            
            while(notUniqueCnt > 0)
            {
                cnt[nums[l]]--;
                if(cnt[nums[l]] == 1) notUniqueCnt--;
                else if(cnt[nums[l]] == 0) sum -= nums[l];
                l++;
            }
            
            if(sum > ans) ans = sum;
        }
        
        return ans;
    }
};
