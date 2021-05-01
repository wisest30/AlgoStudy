class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<array<long long, 3>> A(n);
        for(auto i = 0; i < n; ++i) {
            A[i][0] = tasks[i][0];
            A[i][1] = tasks[i][1];
            A[i][2] = i;
        }
        
        sort(A.begin(), A.end());
        
        priority_queue<array<long long, 2>> q;
        long long cur_time = 0;
        vector<int> ret;
        for(auto i = 0; i < n; ++i) {
            while(cur_time < A[i][0] && !q.empty()) {
                ret.push_back(-q.top()[1]);
                cur_time += -q.top()[0];
                q.pop();
            }
            
            q.push({-A[i][1], -A[i][2]});
            cur_time = max(cur_time, (long long)A[i][0]);
        }
        
        while(!q.empty()) {
            ret.push_back(-q.top()[1]);
            cur_time += -q.top()[0];            
            q.pop();
        }
        
        return ret;
    }
};
