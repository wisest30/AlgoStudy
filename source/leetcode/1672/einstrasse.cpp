class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (auto arr : accounts) {
            ans = max(ans, accumulate(arr.begin(), arr.end(), 0));
        }
        return ans;
    }
};
