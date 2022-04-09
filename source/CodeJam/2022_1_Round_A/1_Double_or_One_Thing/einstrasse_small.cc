#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

string recur(string& s, int index) {
	if (s.length() - 1 == index) {
		return s.substr(index);
	}
}

void solve() {
	string s;
	cin >> s;
	if (s.length() <= 10) {
		vector<string> arr;
		for (int bit = 0; bit < (1 << s.length()); bit++) {
			string tmp = "";
			for (int i = 0; i < s.length(); i++) {
				if (bit & (1 << i)) {
					tmp.push_back(s[i]);
					tmp.push_back(s[i]);
				}
				else {
					tmp.push_back(s[i]);
				}
			}
			arr.push_back(tmp);
		}
		sort(arr.begin(), arr.end());
		cout << arr.front() << endl;
	}
	else {
		cout << "NOWAY\n";
	}
	return;
}
int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}
