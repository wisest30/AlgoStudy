class Solution {
public:
    struct comparePair {
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[0] + a[1] < b[0] + b[1];
        };
    };
    int findMaxValueOfEquation(vector<vector<int>>& P, int k) {
        priority_queue<vector<int>, vector<vector<int>>, comparePair> q;
        auto ret = -INT_MAX;
        for(auto i = (int)P.size()-1; i >= 0; --i) {
            auto xi = P[i][0], yi = P[i][1];
            while(!q.empty() && q.top()[0] - xi > k) q.pop();
            if(!q.empty()) {
                auto xj = q.top()[0], yj = q.top()[1];
                ret = max(ret, yi + yj + abs(xi - xj));
            }
            q.push({xi, yi});
        }
        return ret;
    }
};
