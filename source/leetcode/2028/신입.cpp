class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int total = mean * (n + (int)rolls.size());
        int rollsSum = 0;
        
        for(int roll : rolls) rollsSum += roll;
        
        int target = (total-rollsSum)/n;
        int left = (total-rollsSum)%n;
        
        if(target > 6 || target < 1 || (target == 6 && left)) return vector<int>();
        
        vector<int> ans(n, target);
        for(int i=0;(i<ans.size()) && left;i++, left--) ans[i]++;
        
        return ans;
    }
};
