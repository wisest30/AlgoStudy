#include <queue>
using namespace std;
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> inEdge, outEdge;
        vector<bool> visit;
        inEdge.resize(n, vector<int>());
        outEdge.resize(n, vector<int>());
        visit.resize(n, false);
        for(int i = 0; i < connections.size(); i++){
            int from = connections[i][0];
            int to = connections[i][1];
            outEdge[from].push_back(to);
            inEdge[to].push_back(from);
        }
        
        int count = 0;
        queue<int> q;
        q.push(0);
        visit[0] = true;
        while( !q.empty() ){
            int cur = q.front();
            q.pop();
            for(int i = 0; i < outEdge[cur].size(); i++){
                q.push(outEdge[cur][i]);
                visit[outEdge[cur][i]] = true;
            }
            
            for(int i = 0; i < inEdge[cur].size(); i++){
                if( !visit[inEdge[cur][i]] ){
                    count++;
                    visit[inEdge[cur][i]] = true;
                    q.push(inEdge[cur][i]);
                }
            
            }
        }
        return connections.size() - count;
    }
};
