class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        map<int, int> cntMap;
        for(int i=1;i<nums.size();i++) cntMap[nums[i]]++;
        
        int ans = 0;
        
        int mx = nums[0];
        for(int i=1;i+1<nums.size();i++)
        {
            cntMap[nums[i]]--;
            if(cntMap[nums[i]] == 0) cntMap.erase(nums[i]);
            
            if(nums[i] > mx && nums[i] < cntMap.begin()->first) ans += 2;
            else if(nums[i] > nums[i-1] && nums[i] < nums[i+1]) ans += 1;
            
            mx = max(mx, nums[i]);
        }
        
        return ans;
    }
};
