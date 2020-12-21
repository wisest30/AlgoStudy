#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl '\n'
 
string field[505];
int length[505][505];
int n, m;
int get(int y, int x) {
	int r = 0;
	while (y < n) {
		int s = x - r;
		int e = x + r;
		int num = 2 * r + 1;
		if (s < 0 || e >= m) return r;
		if (length[y][e] < num) return r;
		r++;
		y++;
	}
	return r;
 
}
void solve() {
	memset(length, 0, sizeof(length));
	int ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> field[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (field[i][j] == '*') {
				auto& len = length[i][j];
				if (j == 0) {
					len = 1;
				}
				else {
					auto& prev = length[i][j - 1];
					len = prev + 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (field[i][j] == '*') {
				ans += get(i, j);
			}
		}
	}
	cout << ans << endl;
	return;
	
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) solve();
}
