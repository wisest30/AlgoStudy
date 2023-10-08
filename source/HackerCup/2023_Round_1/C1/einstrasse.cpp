#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <iomanip>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

void invert(string& status, int index, int size) {
	int pos = index;
	while (pos <= size) {
		auto& target = status[pos];
		if (target == '1') {
			target = '0';
		}
		else {
			target = '1';
		}
		pos += index;
	}
}
void solve() {
	int n, q;
	cin >> n;

	string tmp;
	cin >> tmp;
	string status = "-";
	status += tmp;

	cin >> q;
	vector<bool> queried(n + 1, false);
	while (q--) {
		int target;
		cin >> target;
		queried[target] = !queried[target];
	}
	for (int i = 1; i <= n; i++) {
		if (queried[i]) {
			invert(status, i, n);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (status[i] == '1') {
			ans++;
			invert(status, i, n);
		}
	}
	cout << ans << endl;
	return;
}
int main() {
	freopen("output.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}
