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

ll arr[100005];
void solve() {
	double ans = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	if (n != 5) {
		double p = ((double)arr[1] + arr[0]) / 2;
		double q = ((double)arr[n - 1] + arr[n - 2]) / 2;
		ans = q - p;
	}
	else {
		double p = ((double)arr[2] + arr[1] + arr[0]) / 3;
		double q = ((double)arr[n - 1] + arr[n - 2]) / 2;
		ans = q - p;

		double p2 = ((double)arr[1] + arr[0]) / 2;
		double q2 = ((double)arr[n - 1] + arr[n - 2] + arr[n - 3]) / 3;
		ans = max(ans, q2 - p2);
	}

	cout << fixed << setprecision(8) << ans << endl;
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
}
