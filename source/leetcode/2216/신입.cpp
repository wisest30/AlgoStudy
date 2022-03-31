class Solution {
public:
    int minDeletion(vector<int>& nums) {
        // 같은게 3개 이상 있으면 2개로 줄여야함.
        vector<int> newNums;
        nums.push_back(INT_MAX);
        int before = nums[0];
        int cnt = 1;
        int ans = 0;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == before) cnt++;
            else
            {
                newNums.push_back(before);
                if(cnt >= 2) 
                {
                    newNums.push_back(before);
                    ans += cnt-2;
                }
                cnt = 1;
            }
            before = nums[i];
        }
        
        int minus = 0;
        
        for(int i=0;i+1<newNums.size();)
        {
            if(newNums[i] == newNums[i+1])
            {
                minus++;
                i += 3;
            }
            else i += 2;
        }
        
        if(((int)newNums.size() - minus)%2) minus++;
        
        return ans + minus;
    }
};
