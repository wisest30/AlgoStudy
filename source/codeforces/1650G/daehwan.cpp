#include<bits/stdc++.h>

using namespace std;

int n, m, s, t;
vector<vector<int>> adj;
vector<int> dist_S;
vector<int> dist_T;
queue<int> q;
vector<pair<int,int>> dist_node;
vector<unsigned long long> cnt_S;
vector<unsigned long long> cnt_T;

const int MOD = 1e9+7;
void bfs_S(){
    dist_S[s] = 0;
    q = queue<int>();
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(dist_S[u] + 1 < dist_S[v]){
                dist_S[v] = dist_S[u] + 1;
                q.push(v);
            }
        }
    }
    dist_node = vector<pair<int,int>>();
    for(int i=1; i<=n; i++){
        dist_node.push_back(make_pair(dist_S[i], i));
    }
    sort(dist_node.begin(), dist_node.end());
    cnt_S = vector<unsigned long long> (n+1, 0);
    cnt_S[s] = 1;
    for(auto& [d,u] : dist_node){
        for(auto v : adj[u]){
            if(dist_S[v] + 1 == dist_S[u]){
                cnt_S[u] += cnt_S[v];
                cnt_S[u] %= MOD;
            }
        }
    }
}
void bfs_T(){
    dist_T[t] = 0;
    q = queue<int>();
    q.push(t);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(dist_T[u] + 1 < dist_T[v]){
                dist_T[v] = dist_T[u] + 1;
                q.push(v);
            }
        }
    }
    dist_node = vector<pair<int,int>>();
    for(int i=1; i<=n; i++){
        dist_node.push_back(make_pair(dist_T[i], i));
    }
    sort(dist_node.begin(), dist_node.end());
    cnt_T = vector<unsigned long long>(n+1, 0);
    cnt_T[t] = 1;
    for(auto& [d,u] : dist_node){
        for(auto v : adj[u]){
            if(dist_T[v] + 1 == dist_T[u]){
                cnt_T[u] += cnt_T[v];
                cnt_T[u] %= MOD;
            }
        }
    }
}
void solve(int TestCase) {
    cin >> n >> m >> s >> t;
    adj = vector<vector<int>>(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dist_S = vector<int>(n+1, 0x3f3f3f3f);
    dist_T = vector<int>(n+1, 0x3f3f3f3f);

    bfs_S();
    bfs_T();
    
    int ans = cnt_S[t];
    int shortest = dist_S[t];
    for(int u=1; u<=n; u++){
        for(auto v : adj[u]){
            if((dist_S[u] + dist_T[u] == shortest) && (dist_S[u] == dist_S[v])){
                ans += (cnt_S[v] * cnt_T[u])%MOD;
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
