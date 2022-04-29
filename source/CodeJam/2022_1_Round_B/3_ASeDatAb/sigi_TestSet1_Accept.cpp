#include <bits/stdc++.h>

using namespace std;

int T;
vector<vector<unsigned int>>dict;
int count_bit(unsigned int t) {
	int ret = 0;
	while (t > 0) {
		ret += t & 1;
		t >>= 1;
	}
	return ret;
}
string make_binary(unsigned int t) {
	string ret;
	for (int i = 0; i < 8; i++) {
		ret.push_back('0' + t % 2);
		t >>= 1;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
void sol() {
	int ret; 
	cout << "00000000" << endl;
	cin >> ret;
	while (true) {
		if (ret == -1) break;
		if (ret == 0) break;
		int vsize = dict[ret].size();
		int idx = rand() % vsize;
		cout << make_binary(dict[ret][idx])<<endl;
		cin >> ret;
	}

}

int main() {
	cin >> T;
	dict.resize(9);
	for (unsigned int i = 0; i < 256; i++) {
		int bitCnt = count_bit(i);
		dict[bitCnt].push_back(i);
	}
	while (T--) {
		sol();
	}
}
