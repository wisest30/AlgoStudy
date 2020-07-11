class Solution {
public:
    struct comparePair {
        bool operator()(pair<int, int>& x, pair<int, int>& y) {
            return - x.first + x.second < - y.first + y.second;
        };
    };
    int findMaxValueOfEquation(vector<vector<int>>& P, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparePair> q;
        int n = P.size();
        auto ret = -INT_MAX;
        for(auto i = 0; i < n; ++i) {
            while(!q.empty() && P[i][0] - q.top().first > k) q.pop();
            if(!q.empty()) ret = max(ret, P[i][0] - q.top().first + P[i][1] + q.top().second);
            q.push({P[i][0], P[i][1]});
        }
        return ret;
    }
};
