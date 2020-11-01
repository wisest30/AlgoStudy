typedef pair<int, int> pii;
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pii> arr;
        int l = scores.size();
        for (int i=0; i < l; i++) {
            arr.push_back(make_pair(ages[i], scores[i]));
        }
        sort(arr.begin(), arr.end());
        int dp[1005];
        //init
        for (int i=0; i < l; i++) {
            dp[i] = arr[i].second;
        }
        for (int i=0; i < l; i++) {
            for (int j=0; j < i; j++) {
                if (arr[j].second <= arr[i].second) {
                    dp[i] = max(dp[i], dp[j] + arr[i].second);
                }
            }
        }
        int ans = 0;
        for (int i=0; i < l; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};