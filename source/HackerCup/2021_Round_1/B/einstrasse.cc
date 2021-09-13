#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
void fail() {
	cout << "Impossible\n";
}
int field[55][55];
void solve() {
	memset(field, 0, sizeof(field));
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int mini = n + m - 1;
	int maxi = mini * 1000;
	if (a < mini || b < mini || a > maxi || b > maxi) {
		fail();
		return;
	}
	int diffmax = min(n, m) * 999;
	if (abs(a - b) > diffmax) {
		fail();
		return;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			field[i][j] = 1;
		}
	}
	field[0][0] = a - mini + 1;
	field[0][m - 1] = b - mini + 1;


	cout << "Possible\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << field[i][j] << ' ';
		}
		cout << endl;
	}
}
int main() {
	freopen("output.txt", "w", stdout);
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		printf("Case #%d: ", t);
		solve();
	}
}
