#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
void solve() {
	int n;
	set<int> s;
	cin >> n;
	bool ans = false;
	while (n--) {
		int v;
		cin >> v;
		if (s.insert(v).second == false) {
			ans = true;
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	
}
 
int main() {
 
	int tc;
	cin >> tc;
	while (tc--) solve();
	return 0;
}
