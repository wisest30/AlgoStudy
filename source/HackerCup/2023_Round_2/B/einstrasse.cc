#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
int arr[4000005];
int n;
int getA(int index, int time) {
	int i = index + time;
	if (i >= 2 * n) {
		i -= 2 * n;
	}
	return arr[i];
}
int getB(int index, int time) {
	int i = index + time + n;
	if (i >= 2 * n) {
		i -= 2 * n;
	}
	return arr[i];
}
bool isMeta(int time) {
	if (getA(0, time) >= getA(n - 1, time)) {
		return false;
	}
	if (getA(n - 1, time) != getB(0, time)) {
		return false;
	}
	for (int i = 1; i < n; i++) {
		int a = getA(n - 1 - i, time);
		int b = getB(i, time);
//		if (getA(n - 1 - i, time) != getB(i, time)) {
		if (a != b) {
			return false;
		}
	}
	for (int i = 1; i + i + 1 < n; i++) {
		if (getA(i, time) >= getA(n - 1 - i, time)) {
			return false;
		}
	}
	return true;
}
void solve() {
	(void)scanf("%d", &n);
	for (int i = 0; i < n + n; i++) {
		(void)scanf("%d", arr + i);
	}
	for (int t = 0; t < n + n; t++) {
		if (isMeta(t)) {
			cout << t << endl;
			return;
		}
	}
	cout << "-1\n";
	return;
}
int main() {
	freopen("output.txt", "wt", stdout);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}
