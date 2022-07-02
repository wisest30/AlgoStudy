class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        int ans = max(sum1, sum2);
        
        vector<int> diffs;
        int n = nums1.size();
        
        for(int i=0;i<n;i++) diffs.push_back(nums2[i]-nums1[i]);
        
        int curMn = 0;
        int curMx = 0;
        
        for(int i=0;i<n;i++)
        {
            if(curMn + diffs[i] > diffs[i]) curMn = diffs[i];
            else curMn += diffs[i];
            
            if(curMx + diffs[i] < diffs[i]) curMx = diffs[i];
            else curMx += diffs[i];
            
            ans = max({ans, sum1 + curMx, sum2 - curMn});
        }
        
        return ans;
    }
};
