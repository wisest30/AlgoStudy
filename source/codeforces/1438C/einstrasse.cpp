#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int mat[105][105];
void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (((i + j) & 1) && (mat[i][j] & 1)) {
				mat[i][j]++;
			}
			else if ((i + j) % 2 == 0 && mat[i][j] % 2 == 0) {
				mat[i][j]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}
	return;
}
 
int main() {
 
	int tc;
	cin >> tc;
	while (tc--) solve();
	return 0;
}
