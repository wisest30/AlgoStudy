class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> sum(cardPoints.size() + 1, 0);
        for(int i=0;i<cardPoints.size();++i) sum[i+1] = sum[i] + cardPoints[i];
        int ans = 0;
        for(int i=0;i<=k;++i)
        {
            int temp = sum[i] + sum[cardPoints.size()] - sum[cardPoints.size() - (k-i)];
            if(temp > ans) ans = temp;
        }
        return ans;
    }
};
