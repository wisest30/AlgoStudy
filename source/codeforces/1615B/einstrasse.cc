#include <iostream>
#include <cstdio>
using namespace std;
 
using ll = long long;
int nums[33][200005];
void preprocess() {
	for (int i = 1; i <= 200000; i++) {
		for (int j = 0; j < 20; j++) {
			if (i & (1 << j)) {
				nums[j][i] = nums[j][i - 1] + 1;
			}
			else {
				nums[j][i] = nums[j][i - 1];
			}
		}
	}
}
void solve() {
	int l, r;
	cin >> l >> r;
	int total = r - l + 1;
	int ans = total;
	for (int bit = 0; bit < 20; bit++) {
		int candid = total - (nums[bit][r] - nums[bit][l - 1]);
		ans = min(ans, candid);
	}
	cout << ans << endl;
	return;
}
int main() {
	preprocess();
	int tc;
	cin >> tc;
	while (tc--) solve();
	return 0;
}
