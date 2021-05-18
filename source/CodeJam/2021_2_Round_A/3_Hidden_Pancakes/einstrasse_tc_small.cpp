#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 13;
int a[MAXN];
bool used[MAXN];
int v[MAXN];
int n; 
const ll MOD = 1e9 + 7;
int numseen(int p) {
	int ret = 0;
	int prev = -1;
	for (int i = p; i >= 0; i--) {
		if (v[i] > prev) ret++;
		prev = max(prev, v[i]);
	}
	return ret;
}
ll get(int pos) {
	int ret = 0;
	for (int i = 0; i < pos; i++) {
		if (numseen(i) != a[i]) return 0;
	}
	if (pos >= n) {
		return 1;
	}
	for (int i = 0; i < n; i++) {
		if (used[i] == false) {
			used[i] = true;
			v[pos] = i;
			ret += get(pos + 1);
			ret %= MOD;
			used[i] = false;
		}
	}
	return ret;
}
void solve() {
	memset(used, 0, sizeof(used));
	memset(v, -1, sizeof(v));
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << get(0) << endl;
}
int main() {
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		printf("Case #%d: ", t);
		solve();
	}
}
