#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int get(vector<pii>& f, int s, int p, int k) {
	int ret = 0;
	if (s == p) {
		ret = s;
	}
	if (p >= 49900 || f.size() <= k) {
		return ret;
	}
	
	for (int i = 0; i <= f[k].second && p <= 49900; i++) {		
		ret = max(ret, get(f, s, p, k+1));
		s -= f[k].first;
		p *= f[k].first;
	}
	return ret;
}
void solve() {
	int n;
	cin >> n;
	vector<pii> f(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> f[i].first >> f[i].second;
		sum += f[i].first * f[i].second;
	}
	int ans = get(f, sum, 1, 0);
	cout << ans << endl;
}
int main() {
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		printf("Case #%d: ", t);
		solve();
	}
}
