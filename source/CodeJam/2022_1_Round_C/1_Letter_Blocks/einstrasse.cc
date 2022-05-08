#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <assert.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

bool isInvalid(string& s) {
	vector<char> arr;
	for (char c : s) {
		if (arr.empty() || arr.back() != c) {
			arr.push_back(c);
		}
	}
	sort(arr.begin(), arr.end());
	for (size_t i = 1; i < arr.size(); i++) {
		if (arr[i] == arr[i - 1]) {
			return true;
		}
	}
	return false;
}

void solve() {
	int n;
	cin >> n;
	vector<string> arr(n);
	int left = n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (string& s : arr) {
		if (isInvalid(s)) {
			cout << "IMPOSSIBLE\n";
			return;
		}
	} //샌드위치는 다 제거됨
	for (char c = 'A'; c <= 'Z'; c++) {
		vector<string> contain;
		vector<string> notcontain;
		for (string s : arr) {
			if (s.front() == c || s.back() == c) {
				contain.push_back(s);
			}
			else {
				notcontain.push_back(s);
			}
		}
		if (contain.empty()) continue;
		vector<string> front, back, both;
		for (string& s : contain) {
			if (s.front() == s.back()) both.push_back(s);
			else if (s.front() == c) front.push_back(s);
			else if (s.back() == c) back.push_back(s);
			else {
				assert(false);
			}
		}
		if (front.size() > 1 || back.size() > 1) {
			cout << "IMPOSSIBLE\n";
			return;
		}
		string newstr = "";
		if (back.size()) {
			newstr += back.front();
		}
		for (string s : both) {
			newstr += s;
		}
		if (front.size()) {
			newstr += front.front();
		}
		if (isInvalid(newstr)) {
			cout << "IMPOSSIBLE\n";
			return;
		}
		arr.clear();
		for (string s : notcontain) {
			arr.push_back(s);
		}
		arr.push_back(newstr);
	}
	string ans = "";
	for (string s : arr) {
		ans += s;
	}
	if (isInvalid(ans)) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	else {
		cout << ans << endl;
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
