#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int N = 200000;
int n;
 
vector<tuple<int,int,int>> adj[N+1];
int cnt[N+1];
int max_cnt[N+1];
int d[N+1];
vector<int> f[N+1];
int visited1[N+1];
int visited2[N+1];
set<int> used_primes;
int ans = 0;
 
int pow_(int a, int b){
    ll ret = 1, t = a;
    while(b){
        if(b&1) ret = ret * t % MOD;
        t = t * t % MOD;
        b >>= 1;
    }
    return ret;
}
void dfs1(int a, int p){
    visited1[a] = 1;
    for(auto& [b,x,y] : adj[a]){
        if(visited1[b]) continue;
        for(auto& t : f[y]) cnt[t]--;
        for(auto& t : f[x]) {
            cnt[t]++;
            max_cnt[t] = max(max_cnt[t], cnt[t]);
        }
        dfs1(b,a);
        for(auto& t : f[y]) cnt[t]++;
        for(auto& t : f[x]) cnt[t]--;
    }
}
void dfs2(int a, int p, ll val){
    ans = (ans + val) % MOD;
    visited2[a] = 1;
    for(auto& [b,x,y] : adj[a]){
        if(visited2[b]) continue;
        dfs2(b, a, val*y%MOD*pow_(x,MOD-2)%MOD);
    }
}
void solve(int TestCase) {
    cin >> n;
    for(int i=1; i<=n; i++){
        adj[i].clear();
        cnt[i] = max_cnt[i] = visited1[i] = visited2[i] = 0;
    }
    used_primes.clear();
    int a, b, x, y;
    for(int i=0; i<n-1; i++){
        cin >> a >> b >> x >> y;
        adj[a].push_back({b,x,y});
        adj[b].push_back({a,y,x});
        for(int& t : f[x]) used_primes.insert(t);
        for(int& t : f[y]) used_primes.insert(t);
    }
    dfs1(1,-1);
 
    ll lcm=1;
    for(int i : used_primes){
        if(max_cnt[i] > 0){
            lcm = lcm * pow_(i, max_cnt[i]) % MOD;
        }
    }
 
    ans = 0;
    dfs2(1,-1,lcm);
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //Sieve
    for(int i=N; i>1; i--){
        for(int j=i; j<=N; j+=i){
            d[j] = i;
        }
    }
    //primes
    for(int i=1; i<=N; i++){
        for(int x=i; x!=1; x /= d[x]){
            f[i].push_back(d[x]);
        }
    }
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
