#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

const int TG = 1000000;
void subtract(int& ink, int& ovfl) {
	int subt = min(ink, ovfl);
	ink -= subt;
	ovfl -= subt;
}
void solve() {
	int c[3], m[3], y[3], k[3];
	int cc, mm, yy, kk;
	cc = mm = yy = kk = TG;
	for (int i = 0; i < 3; i++) {
		cin >> c[i] >> m[i] >> y[i] >> k[i];
		cc = min(cc, c[i]);
		mm = min(mm, m[i]);
		yy = min(yy, y[i]);
		kk = min(kk, k[i]);
	}
	if (cc + mm + yy + kk < TG) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	int ovfl = cc + mm + yy + kk - TG;
	while (ovfl > 0) {
		if (cc > 0) {
			subtract(cc, ovfl);
			continue;
		}
		if (mm > 0) {
			subtract(mm, ovfl);
			continue;
		}
		if (yy > 0) {
			subtract(yy, ovfl);
			continue;
		}
		if (kk > 0) {
			subtract(kk, ovfl);
			continue;
		}
	}
	cout << cc << ' ' << mm << ' ' << yy << ' ' << kk << endl;
}
int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}
