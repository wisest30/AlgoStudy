#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
ll add(ll n) {
	return n * (n + 1) / 2;
}
void solve() {
	ll ans = 0;
	string str;
	cin >> str;
	vector<pair<char, int>> arr;
	for (int i = 0; i < str.size(); i++) {
		char& c = str[i];
		if (c != '?') {
			if ((i & 1) == c - '0') {
				c = 'A';
			}
			else {
				c = 'B';
			}
		}
	}
	for (char c : str) {
		if (arr.empty() || arr.back().first != c) {
			arr.push_back(make_pair(c, 1));
		}
		else {
			arr.back().second++;
		}
	}
	// A's Perspective
	int s, e;
	s = e = 0;
	while (s < str.size() && e < str.size()) {
		if (str[s] == 'B') {
			s++; e++;
		}
		else if (str[e] == 'A' || str[e] == '?') {
			e++;
		}
		else {
			ans += add(e - s);
			s = e;
		}
	}
	ans += add(e - s);

	//B's Perspective
	s = e = 0;
	while (s < str.size() && e < str.size()) {
		if (str[s] == 'A') {
			s++; e++;
		}
		else if (str[e] == 'B' || str[e] == '?') {
			e++;
		}
		else {
			ans += add(e - s);
			s = e;
		}
	}
	ans += add(e - s);

	for (auto item : arr) {
		if (item.first == '?') {
			ans -= add(item.second);
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
