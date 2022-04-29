#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
vector<string> candid[9];

string int2str(int n) {
	string s = "";
	for (int i = 0; i < 8; i++, n /= 2) {
		s += (n & 1) ? "1" : "0";
	}
	return s;
}
void preprocess() {
	for (int i = 0; i < (1 << 8); i++) {
		int ocnt = 0;
		for (int j = 0; j < 8; j++) {
			if (i & (1 << j)) ocnt++;
		}
		candid[ocnt].push_back(int2str(i));
	}
}
int query(string req) {
	cout << req << endl;
	int resp;
	cin >> resp;
	return resp;
}

void solve() {
	int resp = query("00000000");
	while (resp != 0) {
		int choose = rand() % candid[resp].size();
		resp = query(candid[resp][choose]);
	}
	return;
}
int main() {
	preprocess();
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		solve();
	}
}
