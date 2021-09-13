#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;

void solve() {
	int n; string s;
	cin >> n >> s;

	ll lh, rh, ud, acc;
	lh = rh = ud = acc = 0;
	ll ans = 0;
	for (char c : s) {
		ans += acc;
		ans %= MOD;

		if (c == 'F') {
			ud++;
		}
		else if (c == 'X') { //left hand only
			acc += rh; 
			lh += rh + ud + 1;
			lh %= MOD;
			rh = ud = 0;
		}
		else if (c == 'O') { //right hand only
			acc += lh;
			rh += lh + ud + 1;
			rh %= MOD;
			lh = ud = 0;
		}
	}
	ans += acc;
	ans %= MOD;
	cout << ans << endl;
}
int main() {
	freopen("output.txt", "w", stdout);
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		printf("Case #%d: ", t);
		solve();
	}
}
