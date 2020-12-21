#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl '\n'
 
void solve() {
	int k, n;
	cin >> n >> k;
	string s;
	for (int i = 0; i < n; i++) {
		switch (i % 3) {
		case 0: s += 'a';
			break;
		case 1: s += 'b';
			break;
		default: s += 'c';
		}
	}
	cout << s << endl;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) solve();
}
