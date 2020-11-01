#include <bits/stdc++.h>
using namespace std;
void solve(){
  vector<int> a(6); for(auto& i : a) cin>>i;// sort(a.begin(), a.end());
  int n; cin >> n;
  vector<int> b(n); for(auto& i : b) cin>>i;// sort(b.begin(), b.end());
  
  vector<pair<int,int>> pv;
  for(int i=0; i<6; i++){
    for(int j=0; j<n; j++){
      int p = b[j]-a[i];
      pv.push_back({p,j});
    }
  }
  sort(pv.begin(), pv.end());
  int j=0;
  map<int,int> m;
  int ans = 1e9;
  while((int)m.size()<n && j<(int)pv.size()){m[pv[j++].second]++;}
  for(int i=0; i<(int)pv.size(); i++){
    while((int)m.size()<n && j<(int)pv.size()){m[pv[j++].second]++;}
    if((int)m.size()==n) ans = min(ans, pv[j-1].first-pv[i].first);
    m[pv[i].second]--;
    if(m[pv[i].second]==0) m.erase(pv[i].second);
    //s.insert(pv[i].second);
  }
  cout << ans << endl;
  //cout << "Dd";
}

int main(){
 //int T; cin >> T;
 for(int t=0; t<1; t++){
  solve();
 }
}
