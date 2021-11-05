class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<int> dist(1000+5, INT_MAX);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            for(int num : nums)
            {
                if(cur+num == goal || cur-num == goal || (cur^num) == goal) return dist[cur]+1;

                if(cur+num <= 1000 && cur+num >= 0 && dist[cur]+1 < dist[cur+num])
                {
                    dist[cur+num] = dist[cur]+1;
                    q.push(cur+num);
                }
                if(cur-num <= 1000 && cur-num >= 0 && dist[cur]+1 < dist[cur-num])
                {
                    dist[cur-num] = dist[cur]+1;
                    q.push(cur-num);
                }
                if((cur^num) <= 1000 && (cur^num) >= 0 && dist[cur]+1 < dist[(cur^num)])
                {
                    dist[cur^num] = dist[cur]+1;
                    q.push(cur^num);
                }
            }
        }
        
        return -1;
    }
};
