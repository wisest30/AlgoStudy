#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll mxone = 0;
	vector<ll> sz;
	sz.push_back(a.front() - 1);
	sz.push_back(k - a.back());
	for (int i = 1; i < a.size(); i++) {
		ll prev = a[i - 1];
		ll cur = a[i];
		mxone = max(mxone, cur - prev - 1);
		sz.push_back((cur - prev) / 2);
	}
	sort(sz.begin(), sz.end(), greater<ll>());
	double ans = (double)max(sz[0] + sz[1], mxone) / k;
	cout << setprecision(6) << ans << endl;;

}
int main() {
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		printf("Case #%d: ", t);
		solve();
	}
}
