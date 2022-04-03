#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;


void solve() {
	int ans = 0;
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int cur = 1;
	for (int v : arr) {
		if (v >= cur) {
			ans++;
			cur++;
		}
	}
	cout << ans << endl;
	return;
}
int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}
