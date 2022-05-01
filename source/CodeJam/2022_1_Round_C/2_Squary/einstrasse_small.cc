#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;


ll error(ll A, ll S, ll C) {
	return (S + C) * (S + C) - (A + C * C);
}
int getSign(ll v) {
	if (v > 0) return 1;
	if (v == 0) return 0;
	if (v < 0) return -1;
}
pair<ll, bool> search(ll start, ll end, ll unit, ll A, ll S) {
	for (ll v = start; v + unit <= end; v += unit) {
		ll err1 = error(A, S, v);
		ll err2 = error(A, S, v + unit);
		int s1 = getSign(err1);
		int s2 = getSign(err2);
		if (s1 * s2 == 0) {
			return make_pair(err1 == 0 ? v : v + unit, true);
		}
		else if (unit >= 10 && s1 * s2 < 0) {
			return search(v, v + unit, unit / 10, A, S);
		}
	}
	return make_pair(-1, false);
}
void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> e(n);
	for (int i = 0; i < n; i++) {
		cin >> e[i];
	}
	ll A = 0;
	ll S = 0;
	for (int i : e) {
		A += i * i;
		S += i;
	}

	auto res = search(-1e9, 1e9, 1e8, A, S);
	if (res.second == false) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		cout << res.first << endl;
	}
	return;
}
int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}
