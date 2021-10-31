class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        for(auto& e : events) e[1]++;
        sort(events.begin(), events.end());
        
        vector<int> A(n);
        for(auto i = 0; i < n; ++i) A[i] = events[i][2];
        for(auto i = n-2; i >= 0; --i) A[i] = max(A[i], A[i+1]);
        int ret = A[0];
        for(auto i = 0; i < n; ++i) {
            auto p = lower_bound(events.begin() + i, events.end(), vector<int>{events[i][1], 0, 0}) - events.begin();
            if(p < n)
                ret = max(ret, events[i][2] + A[p]);
        }
        
        return ret;
    }
};
