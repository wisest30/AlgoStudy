class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, -1e9));
        for(int i = 0; i <= nums1.size(); i++){
            for(int j = 0; j <= nums2.size(); j++){
                if( j )
                    dp[i][j] = dp[i][j-1];
                if( i )
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if( i && j ){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + nums1[i-1] * nums2[j-1]);
                    dp[i][j] = max(dp[i][j], nums1[i-1] * nums2[j-1]);
                }
                
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};
