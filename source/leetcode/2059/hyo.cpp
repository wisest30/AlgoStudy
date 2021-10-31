class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        
        queue<array<int, 2>> q;
        q.push({start, 0});
        vector<bool> visited(1001);
        while(!q.empty()) {
            auto cur = q.front()[0];
            auto d = q.front()[1];
            q.pop();
            
            if(cur == goal)
                return d;
            if(cur < 0 || cur > 1000)
                continue;
            if(visited[cur]) continue;
            visited[cur] = true;
            
            for(auto a : nums) {
                q.push({cur + a, d+1});
                q.push({cur - a, d+1});
                q.push({cur ^ a, d+1});
            }
        }
        
        return -1;
    }
};
