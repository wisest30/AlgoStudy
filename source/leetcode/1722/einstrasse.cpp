class Solution {
    vector<int> adj[100005];
    bool chk[100005];
    set<int> indexes;
    void dfs(int node) {
        indexes.insert(node);
        for (int p : adj[node]) {
            if (chk[p] == false) {
                chk[p] = true;
                indexes.insert(p);
                dfs(p);
            }
        }
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        memset(chk, 0, sizeof(chk));
        for (int i=0; i< 100000; i++) {
            adj[i].clear();
        }
        int ans = 0;
        for (vector<int>& p : allowedSwaps) {
            int a = p[0];
            int b = p[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i=0; i < source.size(); i++) {
            if (chk[i] == false) {
                indexes.clear();
                chk[i] = true;
                dfs(i);
                vector<int> p;
                multiset<int> q;
                p.clear(); q.clear();
                for (int index : indexes) {
                    p.push_back(source[index]);
                    q.insert(target[index]);
                }
                for (int v : p) {
                    if (q.find(v) == q.end()) {
                        ans++;
                    } else {
                        q.erase(q.find(v));
                    }
                }
            }
        }
        return ans;
    }
};
