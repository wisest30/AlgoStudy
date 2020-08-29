static auto io_sync_off = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int N;
    int ans;
    
    void qAndMapUpdate(unordered_map<int, int> &thisDist, unordered_map<int, int> &otherDist, queue<int> &q, int next, int curDist)
    {
        if(otherDist.find(next) != otherDist.end())
        {
            ans = otherDist[next] + curDist + 1;
            return;
        }
        else if(thisDist.find(next) == thisDist.end()) 
        {
            thisDist[next] = curDist+1;
            q.push(next);
        }        
    }
    
    void update(unordered_map<int, int> &thisDist, unordered_map<int, int> &otherDist, queue<int> &q, int dir)
    {
        int n = q.size();
        
        while(n-- && ans == INT_MAX)
        {
            int cur = q.front();
            q.pop();
            
            int curDist = thisDist[cur];
            
            if((dir == 0 && cur+1 <= N) || (dir == 1 && cur-1 >= 0))
            {
                int next = cur-1;
                if(dir == 0) next = cur+1;
                qAndMapUpdate(thisDist, otherDist, q, next, curDist);
            }
            
            if((dir == 0 && 1LL*cur*2 <= 1LL*N) || (dir == 1 && cur%2 == 0))
            {
                int next = cur/2;
                if(dir == 0) next = cur*2;
                qAndMapUpdate(thisDist, otherDist, q, next, curDist);
            }
            
            if((dir == 0 && 1LL*cur*3 <= 1LL*N) || (dir == 1 && cur%3 == 0))
            {
                int next = cur/3;
                if(dir == 0) next = cur*3;
                qAndMapUpdate(thisDist, otherDist, q, next, curDist);
            }
        }
    }
    
    int minDays(int n) {
        ans = INT_MAX;
        N = n;
        
        unordered_map<int, int> dist[2];
        queue<int> q[2];
        
        dist[0][0] = 0;
        dist[1][n] = 0;
        
        q[0].push(0);
        q[1].push(n);
        
        int dir;
        
        while(ans == INT_MAX)
        {
            if(q[1].size() <= q[0].size()) dir = 1;
            else dir = 0;
            
            update(dist[dir], dist[1-dir], q[dir], dir);
        }
        
        return ans;
    }
};
