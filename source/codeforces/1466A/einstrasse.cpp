#include <bits/stdc++.h> 
using namespace std;
#define endl '\n'
typedef long long ll;
int arr[55];
void solve() {
	int n;
  cin >> n;
  for (int i=0; i < n; i++) cin >> arr[i];
  set<int> ss;
  for (int i=0; i < n;i++) {
    for (int j=i+1; j < n;j++) {
      ss.insert(arr[j] - arr[i]);
    }
  }
  cout << ss.size() << endl;
}
 
int main() {
    int tc;
    cin >> tc;
    while(tc--) solve();
    return 0;
}
