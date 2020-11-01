#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n; cin>>n;
  vector<int> arr(2*n);
  for(int i=0; i<2*n; i++){
    char tmp; cin>>tmp;
    if(tmp=='+') arr[i]=0;
    if(tmp=='-'){cin>>arr[i];}
  }
  priority_queue<int, vector<int>, greater<int>> pq;
  vector<int> ans;
  for(int i=2*n-1; i>=0; i--){
    if(arr[i]==0){
      if(pq.empty()){cout << "NO" << endl; return;}
      ans.push_back(pq.top()); pq.pop(); continue;
    }

    if(!pq.empty() && arr[i] > pq.top()){cout << "NO" << endl; return;}
    pq.push(arr[i]);
  }
  if((int)ans.size()!=n){cout << "NO" << endl; return;}

  cout << "YES" << endl;
  reverse(ans.begin(), ans.end());
  for(int i=0; i<n; i++) cout << ans[i] << " ";
  cout << endl;
}

int main(){
 //int T; cin >> T;
 for(int t=0; t<1; t++){
  solve();
 }
}
