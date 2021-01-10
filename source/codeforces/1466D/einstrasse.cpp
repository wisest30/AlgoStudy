#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
void solve() {
	long long ans = 0;
	int n;
	cin >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		ans += v[i].first;
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a - 1].second++;
		v[b - 1].second++;
	}
	sort(v.begin(), v.end(), greater<pii>());
	int k = 0;
	for (int i = 1; i < n; i++) {
		cout << ans << ' ';
		while (k < n && v[k].second <= 1) k++;
		if (k < n) {
			ans += v[k].first;
			v[k].second--;
		}
	}
	cout << endl;
	return;
}
 
int main() {
 
	int tc;
	cin >> tc;
	while (tc--) solve();
	return 0;
}
