class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int trav_time = 0;
        vector<vector<int>> e(n, vector<int>(0));
        vector<bool> visit(n, false);
        for(int i = 0; i < edges.size(); i++){
            e[edges[i][0]].push_back(edges[i][1]);
            e[edges[i][1]].push_back(edges[i][0]);
        }
        trav_time = traverse_time(0, e, hasApple, visit) * 2;
        
        return trav_time;
    }
private:
    int traverse_time(int cur, vector<vector<int>> &e, vector<bool>& hasApple, vector<bool>& visit){
        int child_trav_time = 0;
        int trav_time = 0;
        visit[cur] = true;
        for(int i = 0; i < e[cur].size(); i++){
            int child = e[cur][i];
            if( !visit[child])
                child_trav_time += traverse_time(child, e, hasApple, visit);
        }
        
        trav_time = child_trav_time;
        if((child_trav_time || hasApple[cur]) && cur )
            trav_time++;
        return trav_time;
        
    }
};
