#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n; cin>>n;
  vector<vector<int>> vv[31];
  vector<int> tmp(n);
  for(int i=0; i<n; i++){cin>>tmp[i];}
  vv[30].push_back(tmp);
  
  int x = 0; long long cnt = 0;
  for(int i=30; i>=0; i--){
    int ones=0, zeros=0;
    long long zero2one=0, one2zero=0;
    //vector<int> nzv, nov;
    for(int j=0; j<(int)vv[i].size(); j++){
      if(vv[i][j].size()<=1) continue;
      ones = zeros = 0;
      vector<int> nzv(0), nov(0);
      for(int k=0; k<(int)vv[i][j].size(); k++){
        if(vv[i][j][k] & (1<<i)){
          nov.push_back(vv[i][j][k]);
          ones++;
          zero2one += zeros;
        }else{
          nzv.push_back(vv[i][j][k]);
          zeros++;
          one2zero += ones;
        }
      }
      if(i>0){
        if(nzv.size()>0) vv[i-1].push_back(nzv);
        if(nov.size()>0) vv[i-1].push_back(nov);
      }
    }
    if(one2zero > zero2one) {x += (1<<i);}
    cnt += min(one2zero, zero2one);
    // else ans+= (0<<i);
  }
  cout << cnt << " " << x << endl;
}

int main(){
 //int T; cin >> T;
 for(int t=0; t<1; t++){
  solve();
 }
}
