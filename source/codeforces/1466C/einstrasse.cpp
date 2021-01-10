#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
vector<int> idx[26];
void solve() {
	string s;
	cin >> s;
	for (int i = 0; i < 26; i++) idx[i].clear();
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		idx[c - 'a'].push_back(i);
	}
	int ans = 0;
	for (int k = 0; k < 26; k++) {
		auto& arr = idx[k];
		if (arr.size() < 2) continue;
		if (arr.size() == 2) {
			if (arr[1] - arr[0] <= 2) ans++;
			continue;
		}
		int prev = arr[0];
		for (int i = 1; i < arr.size(); i++) {
			int cur = arr[i];
			if (cur - prev <= 2) {
				ans++;
			}
			else {
				prev = cur;
			}
		}
	}
	cout << ans << endl;
	return;
}
 
int main() {
 
	int tc;
	cin >> tc;
	while (tc--) solve();
	return 0;
}
