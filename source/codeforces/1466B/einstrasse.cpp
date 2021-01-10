#include <bits/stdc++.h> 
using namespace std;
#define endl '\n'
typedef long long ll;
int a[100005];
bool chk[200005];
void solve() {
  memset(chk, 0, sizeof(chk));
  int ans = 0;
	int n; cin >> n;
  for (int i=0; i < n; i++) cin >> a[i];
  for (int i=0; i< n; i++) {
    int& c = a[i];
    if (chk[c] == false) {
      chk[c] = true;
      ans++;
    } else {
      c++;
      ans += chk[c] == false ? 1 : 0;
      chk[c] = true;
    }
  }
  cout << ans << endl;
}
 
int main() {
    int tc;
    cin >> tc;
    while(tc--) solve();
    return 0;
}
