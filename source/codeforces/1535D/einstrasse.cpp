#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl '\n'
 
int lc[2 << 18], rc[2 << 18], p[2 << 18]; //left child, right child, parent
int ans[2 << 18];
void solve() {
	memset(ans, 0, sizeof(ans));
	ans[0] = 1;
	int k;
	string s = "-";
	cin >> k;
	{
		string tmp;
		cin >> tmp;
		s.append(tmp);
	}
	int index = 1;
	for (int e = k - 1; e > 0; e--) {
		int start = index;
		index += (1 << e);
		int end = index;
 
		int parent = index;
		for (int i = start; i < end; i += 2) {
			lc[parent] = i;
			rc[parent] = i + 1;
			p[i] = parent;
			p[i + 1] = parent;
			parent++;
		}
	}
	for (int i = 1; i < (1 << k); i++) {
		if (s[i] == '0') {
			ans[i] = max(1, ans[lc[i]]);
		}
		else if (s[i] == '1') {
			ans[i] = max(1, ans[rc[i]]);
		}
		else { //s[i] == '?'
			assert(s[i] == '?');
			ans[i] = max(ans[lc[i]] + ans[rc[i]], 1);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int pos;
		char val;
		scanf("%d %c\n", &pos, &val);
		s[pos] = val;
		if (val == '?') {
			ans[pos] = max(ans[lc[pos]] + ans[rc[pos]], 1);
 
			int i = p[pos];
			while (i) {
				if (s[i] == '?') {
					ans[i] = max(ans[lc[i]] + ans[rc[i]], 1);
				}
				else if (s[i] == '0') {
					ans[i] = max(1, ans[lc[i]]);
				}
				else if (s[i] == '1') {
					ans[i] = max(1, ans[rc[i]]);
				}
				i = p[i];
			}
		}
		else if (val == '0') {
			ans[pos] = max(1, ans[lc[pos]]);
			int i = p[pos];
			while (i) {
				if (s[i] == '?') {
					ans[i] = max(ans[lc[i]] + ans[rc[i]], 1);
				}
				else if (s[i] == '0') {
					ans[i] = max(1, ans[lc[i]]);
				}
				else if (s[i] == '1') {
					ans[i] = max(1, ans[rc[i]]);
				}
				i = p[i];
			}
		}
		else if (val == '1') {
			ans[pos] = max(1, ans[rc[pos]]);
			int i = p[pos];
			while (i) {
				if (s[i] == '?') {
					ans[i] = max(ans[lc[i]] + ans[rc[i]], 1);
				}
				else if (s[i] == '0') {
					ans[i] = max(1, ans[lc[i]]);
				}
				else if (s[i] == '1') {
					ans[i] = max(1, ans[rc[i]]);
				}
				i = p[i];
			}
		}
		cout << ans[(1<<k) - 1] << endl;
	}
	return;
 
}
int main() {
	solve();
}
