#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl '\n'
void solve() {
	int x; cin >> x;
	for (int i = 1; i <= 1000000; i++) {
		x -= i;
		if (x == 0 || x <= -2) {
			cout << i << endl;
			return;
		}
	}
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) solve();
}
