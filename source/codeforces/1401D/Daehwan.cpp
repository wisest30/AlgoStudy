#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M = 1e9+7;
ll mod(ll x){return x%M;}
ll mul(ll a, ll b){return mod(mod(a)*mod(b));}
ll add(ll a, ll b){return mod(mod(a)+mod(b));}
 
void solve(){
  int n; cin >> n;
  vector<vector<int>> adj(n);
  for(int i=0; i<n-1; i++){
    int u, v; cin >> u >> v;
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }
  int m; cin >> m;
  vector<ll> p(m);
  for(int i=0; i<m; i++) cin >> p[i];
  sort(p.begin(), p.end(), greater<ll>());
 
  vector<ll> cnt;
 
  function<ll(int,int)> dfs=[&](int u, int p)->ll{
    int ret = 1;
    for(auto v : adj[u]){
      if(v==p) continue;
      ll t = dfs(v,u);
      cnt.push_back(t*(n-t));
      ret += t;
    }
    return ret;
  };
 
  dfs(0,-1);
  sort(cnt.begin(), cnt.end(), greater<ll>());
 
  if(n-1>m){
    for(int i=0; i<n-1-m; i++) p.push_back(1LL);
    sort(p.begin(), p.end(), greater<ll>());
  }
  if(m>n-1){
    for(int i=0; i<m-n+1; i++){
      p[i+1]=mul(p[i],p[i+1]);
    }
    p = vector<ll>(p.begin()+m-n+1, p.end());
  }
 
  ll ans = 0;
  for(int i=0; i<n-1; i++){ans=add(ans,mul((ll)cnt[i],p[i]));}
  cout << ans << endl;
}
 
int main(){
  int T; cin >> T;
  for(int t=0; t<T; t++) solve();
  return 0;
}
