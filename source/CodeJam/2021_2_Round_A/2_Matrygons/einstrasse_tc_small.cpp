#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

constexpr int MAXN = 1001;
constexpr int NOTFOUND = -987654321;
int dp[MAXN][MAXN];
pii pv[MAXN][MAXN];
int f(int t, int p) {
	int& ret = dp[t][p];
	if (ret != -1) return ret;
	ret = 0;
	if (t == 0) return 0;
	bool found = false;
	for (int i = 2; i * i <= p; i++) {
		if (p % i == 0) {
			int j = p / i;
			if (t - i >= 0 && i >= 3) {
				int r = f(t - i, i) + 1;
				if (ret < r) {
					ret = r;
					found = true;
					pv[t][p].first = t - i;
					pv[t][p].second = i;
				}
			}
			if (t - j >= 0 && j >= 3) {
				int r = f(t - j, j) + 1;
				if (ret < r) {
					ret = r;
					found = true;
					pv[t][p].first = t - j;
					pv[t][p].second = j;
				}
			}
		}
	}
	if (found) return ret;
	else return ret = NOTFOUND;
}

void solve() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 3; i <= n; i++) {
		int ret = f(n - i, i) + 1;
		if (ans < ret) {
			ans = ret;
		}
	}
	cout << ans << endl;
	return;
}
int main() {
	memset(dp, -1, sizeof(dp));
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}
