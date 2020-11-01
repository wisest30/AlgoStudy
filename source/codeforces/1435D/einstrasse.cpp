#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
void fail() {
	cout << "NO\n";
	exit(EXIT_SUCCESS);
}
void solve() {
	int ptr = 0;
	int n;
	cin >> n;
	vector<int> arr;
	vector<int> ss;
	vector<int> val(n);
	arr.reserve(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		char cmd;
		cin >> cmd;
		if (cmd == '+') {
			arr.push_back(ptr++);
		}
		else {
			int v;
			cin >> v;
			arr.push_back(-v);
		}
	}
	for (int i = 0; i < 2 * n; i++) {
		int& v = arr[i];
		if (v >= 0) {
			ss.push_back(v);
		}
		else {
			if (ss.empty()) {
				fail();
			}
			val[ss.back()] = -v;
			ss.pop_back();
		}
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < 2 * n; i++) {
		int& v = arr[i];
		if (v >= 0) {
			pq.push(val[v]);
		}
		else {
			if (pq.top() != -v) fail();
			pq.pop();
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		cout << val[i] << ' ';
	}
	return;
}
 
int main() {
	solve();
	return 0;
}