#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl '\n'
 
int arr[505];
int n, x;
int last() {
	//마지막으로 만족하는녀석 index 리턴
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] > arr[i])
			return i;
	}
	return n;
}
void solve() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int r;
	int ans = 0;
	while ((r = last()) < n) {
		int pos = upper_bound(arr, arr + r, x) - arr;
		if (arr[pos] <= x) {
			cout << -1 << endl;
			return;
		}
		swap(arr[pos], x);
		ans++;
	}
	cout << ans << endl;
 
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) solve();
}
