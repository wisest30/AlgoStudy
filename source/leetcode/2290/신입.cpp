struct Element
{
    int r;
    int c;
    int mov;
};

class Solution {
public:
    int R;
    int C;
    
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    
    int minimumObstacles(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        
        deque<Element> dq;
        vector<vector<int>> dist(R, vector<int>(C, INT_MAX));
        
        dq.push_back({0, 0, 0});
        dist[0][0] = 0;
        
        while(!dq.empty())
        {
            Element cur = dq.front();
            dq.pop_front();
            
            if(cur.r == R - 1 && cur.c == C - 1) return cur.mov;
            
            for(int i=0;i<4;i++)
            {
                int nr = cur.r + dr[i];
                int nc = cur.c + dc[i];
                
                if(nr >= R || nr < 0 || nc >= C || nc < 0) continue;
                
                if(grid[nr][nc] == 1 && cur.mov+1 < dist[nr][nc])
                {
                    dist[nr][nc] = cur.mov+1;
                    dq.push_back({nr, nc, cur.mov+1});
                }
                else if(grid[nr][nc] == 0 && cur.mov < dist[nr][nc])
                {
                    dist[nr][nc] = cur.mov;
                    dq.push_front({nr, nc, cur.mov});
                }
            }
        }
        
        return -1;
    }
};
