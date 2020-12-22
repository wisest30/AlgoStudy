#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl '\n'
 
int arr[100005];
void solve() {
	double comp = 1.0;
	int n, m;
	cin >> n >> m;
	int need = n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] == i + 1) {
			need--;
		}
		else {
			break;
		}
	}
	while (m--) {
		int r;
		double p;
		cin >> r >> p;
		if (r < need || need == 0) continue;
		comp *= (1 - p);
	}
	cout << setprecision(6) << fixed << (need == 0 ? 1.0 : (1 - comp)) << endl;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) solve();
}
