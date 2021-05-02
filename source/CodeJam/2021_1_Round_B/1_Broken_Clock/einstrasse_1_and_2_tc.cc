#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <assert.h>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
const ll nnsec = 1e9;
const ll ROUND = 360LL * 12 * 1e10;
map<pair<int, int>, int> tt;
void solve() {
	/*
	1시간 = 60분 = 3600초
	12시간 = 720분 = 43200초

	hours = 1tick
	minute = 12tick
	second =  720tick
	*/
	ll angle[3];
	int pos[3];
	for (int i = 0; i < 3; i++) {
		cin >> angle[i];
		pos[i] = i;
	}
	
	do {
		//hour, min, sec?
		ll h = angle[pos[0]];
		ll m = angle[pos[1]];
		ll s = angle[pos[2]];
		ll hama = (h - m) / nnsec % (3600 * 12);
		if (hama < 0) hama += 3600 * 12;
		ll hasa = (h - s) / nnsec % (3600 * 12);
		if (hasa < 0) hasa += 3600 * 12;
		if (tt.find(make_pair(hama, hasa)) != tt.end()) {
			ll Time = tt[make_pair(hama, hasa)];
			ll nanosec, second, minute, hour;
			nanosec = 0;
			second = Time % 60;
			Time /= 60;
			minute = Time % 60;
			Time /= 60;
			hour = Time;
			cout << hour << ' ' << minute << ' ' << second << ' ' << nanosec << endl;
			return;
		}

	} while (next_permutation(pos, pos + 3));
}
int main() {
	for (int i = 0; i < 3600 * 12; i++) {
		ll ha = i; //hour angle
		ll ma = i * 12 % (3600 * 12); //minute angle
		ll sa = i * 720 % (3600 * 12);//second angle

		ll A = ha - ma;
		if (A < 0) A += 3600 * 12;
		ll B = ha - sa;
		if (B < 0) B += 3600 * 12;
		tt[make_pair(A, B)] = i;
		//tt[make_pair(ha - ma, ha - sa)] = i; //초단위로 저장
	}

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";
		solve();

	}
}
