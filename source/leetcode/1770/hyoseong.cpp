class Solution {
public:
    vector<int> nums;
    vector<int> multipliers;
    vector<vector<int>> dp;
    int N;
    
    int recur(int i, int j) {
        if(i == N) return 0;
        
        auto& ret = dp[i][j];
        if(ret != -1) return ret;
        
        auto candi1 = multipliers[i] * nums[j] + recur(i + 1, j + 1);
        auto candi2 = multipliers[i] * nums[(int)nums.size() - (i - j) - 1] + recur(i + 1, j);
        
        return ret = max(candi1, candi2);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        this->N = multipliers.size();
        this->nums = nums;
        this->multipliers = multipliers;
        this->dp = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
        
        auto ret = recur(0, 0);
        return ret;
    }
};
