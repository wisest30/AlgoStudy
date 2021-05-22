class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        
        for(int i=0;i<nums1.size();i++)
        {
            int j = i;
            
            int left = i;
            int right = (int)nums2.size()-1;
            
            while(left <= right)
            {
                int mid = left + (right - left)/2;
                
                if(nums2[mid] >= nums1[i])
                {
                    j = mid;
                    left = mid + 1;
                }
                else right = mid - 1;
            }
            
            ans = max(ans, j-i);
        }
        
        return ans;
    }
};
