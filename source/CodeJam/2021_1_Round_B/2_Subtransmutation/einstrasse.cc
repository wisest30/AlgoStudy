#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <assert.h>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
#define ANSLIMIT 800
int u[ANSLIMIT];
int m[ANSLIMIT];//mytest
int n, a, b;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
bool test(int start) {
	memset(m, 0, sizeof(m));
	m[start] = 1;
	for (int i = start; i >= 0; i--) {
		while (m[i] > u[i]) {
			m[i]--;
			if (i - a >= 0) {
				m[i - a]++;
			}
			if (i - b >= 0) {
				m[i - b]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (u[i] > m[i]) return false;
	}
	return true;
}
void solve() {
	memset(u, 0, sizeof(u));
	cin >> n >> a >> b;
	vector<int> pos;
	for (int i = 0; i < n; i++) {
		cin >> u[i];
		if (u[i]) pos.push_back(i);
	}
	int g = gcd(a, b);
	if (pos.size() > 1) {
		int k = pos[0] % g;
		for (int i = 1; i < pos.size(); i++) {
			if (pos[i] % g != k) {
				cout << "IMPOSSIBLE\n";
				return;
			}
		}
	}
	for (int i = n; i < ANSLIMIT; i++) {
		if (test(i)) {
			cout << (i+1) << endl;
			return;
		}
	}
	assert(false);
}
int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";
		solve();

	}
}
