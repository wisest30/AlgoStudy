#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n; cin>>n;
  int s=0;
  vector<int> nums(n+1); for(int i=1; i<=n; i++) {cin>>nums[i]; s+=nums[i];}
  if(s%n){cout<<-1<<endl; return;}
  s /= n;
  int cnt = 0;
  vector<vector<int>> oper;
  for(int i=2; i<=n; i++){
    if(nums[i]%i){int diff=i-nums[i]%i; cnt++; oper.push_back({1,i,diff}); nums[1]-=diff; nums[i]+=diff;}
    int m = nums[i]/i;
    cnt++; oper.push_back({i,1,m}); nums[i]-=m*i; nums[1]+=m*i;
  }
  /*
  for(int i=2; i<=n; i++){
    if(nums[i]>s){cout<<-1<<endl; return;} 
  }
  */
  for(int i=2; i<=n; i++){
    if(nums[i]==s) continue;
    int diff = s-nums[i];
    cnt++; oper.push_back({1,i,diff});
  }
  cout<<cnt<<endl;
  for(int i=0; i<cnt; i++){
    cout << oper[i][0] << " " << oper[i][1] << " " << oper[i][2] << endl;
  }
}

int main(){
 int T; cin >> T;
 for(int t=0; t<T; t++){
  solve();
 }
}
