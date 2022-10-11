class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        auto ret = make_pair(-1, 0);
        for(auto i = 0; i < logs.size(); ++i)
            ret = max(ret, make_pair(logs[i][1] - (i ? logs[i-1][1] : 0), -logs[i][0]));
        return -ret.second;
    }
};