class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = INT_MAX;
        int mnIdx = -1;
        
        int mx = INT_MIN;
        int mxIdx = -1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] < mn)
            {
                mn = nums[i];
                mnIdx = i;
            }
            
            if(nums[i] > mx)
            {
                mx = nums[i];
                mxIdx = i;
            }
        }
        
        if(mnIdx > mxIdx) swap(mnIdx, mxIdx);
        
        return min({max(mnIdx, mxIdx)+1, 
                    max((int)nums.size() - mnIdx, (int)nums.size() - mxIdx),
                    mnIdx+1 + (int)nums.size()-mxIdx});
    }
};
