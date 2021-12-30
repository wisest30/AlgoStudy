#include <iostream>
#include <cstdio>
using namespace std;
 
using ll = long long;
void solve() {
	int a[105];
	int n;
	cin >> n;
	int total = 0;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		total += tmp;
	}
	if (total % n == 0) {
		cout << 0 << endl;
	}
	else {
		cout << 1 << endl;
	}
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) solve();
	return 0;
}
