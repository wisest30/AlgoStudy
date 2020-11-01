#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
void solve() {
	int n;
	cin >> n;
	vector<int> a;
	a.reserve(n);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < n; i += 2) {
		cout << -a[i + 1] << ' ' << a[i] << ' ';
	}
	cout << endl;
}
 
int main() {
 
	int tc;
	cin >> tc;
	while (tc--) solve();
	return 0;
}