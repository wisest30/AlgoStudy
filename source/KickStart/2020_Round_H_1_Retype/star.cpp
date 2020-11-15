#include <bits/stdc++.h>
using namespace std;

void solve(int testNum){
  long long n, k, s;
  cin >> n >> k >> s;
  long long ans = min((n - k) + 2*(k - s), n) + k;
  cout << "Case #" << testNum << ": " << ans << "\n";
  return;
}

int main(){
  int T;
  cin >> T;
    for(int t = 1; t<= T; ++t){
      solve(t);
    }
  return 0;
}