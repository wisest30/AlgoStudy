#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
string inv(string s) {
	string ret = "";
	for (char c : s) {
		if (c == 'T') {
			ret += string("F");
		}
		else {
			ret += string("T");
		}
	}
	return ret;
}
void solve() {
	int n, q;
	cin >> n >> q;
	vector<pair<int, string>> data(n);
	
	for (int i = 0; i < n; i++) {
		cin >> data[i].second >> data[i].first;
	}
	for (int i = 0; i < n; i++) {
		auto item = make_pair(q - data[i].first, inv(data[i].second));
		data.push_back(item);
	}
	sort(data.begin(), data.end());
	
	cout << data.back().second << ' ' << data.back().first << "/1\n";
	
	
}
int main() {
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		printf("Case #%d: ", t);
		solve();
	}
}
