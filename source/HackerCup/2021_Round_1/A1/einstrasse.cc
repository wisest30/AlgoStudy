#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
void solve() {
	int n; string s;
	cin >> n >> s;
	int ans = n;
	for (int start = 0; start < 2; start++) {
		int aans = 0;
		bool left = start;
		for (int i = 0; i < n; i++) {
			char c = s[i];
			if (c == 'F') continue;
			if (c == 'X' && !left) {
				left ^= 1;
				aans++;
			}
			else if (c == 'O' && left) {
				left ^= 1;
				aans++;
			}
		}
		ans = min(ans, aans);
	}
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
