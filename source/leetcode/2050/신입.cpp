class Solution {
public:
    int indegree[5'0000+5];
    int arriveTime[5'0000+5];
    vector<int> adj[5'0000+5];
    
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        for(auto &relation : relations)
        {
            relation[0]--, relation[1]--;
            indegree[relation[1]]++;
            adj[relation[0]].push_back(relation[1]);
        }
        
        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            for(auto &next : adj[cur])
            {
                indegree[next]--;
                arriveTime[next] = max(arriveTime[next], arriveTime[cur] + time[cur]);
                if(indegree[next] == 0) q.push(next);
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++) ans = max(ans, arriveTime[i] + time[i]);    
        return ans;
    }
};
