#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
int N;
int query(int a, int b) {
	cout << "M " << a << " " << b << endl;
	cout.flush();
	int resp;
	cin >> resp;
	return resp;
}
void swp(int a, int b) {
	cout << "S " << a << ' ' << b << endl;
	cout.flush();
	int resp;
	cin >> resp;
	assert(resp != -1);
}
void done() {
	cout << "D\n";
	cout.flush();
	int resp;
	cin >> resp;
	assert(resp == 1);
}
void solve() {
	for (int i = 1; i < N; i++) {
		int p = query(i, N);
		if (p != i) {
			swp(i, p);
		}
	}
	done();
}
int main() {
	int T;
	cin >> T >> N;
	while (T--) solve();
}
