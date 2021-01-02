#include <iostream>
#include <vector>
using namespace std;
void solve() {
	int n;
	cin >> n;
	string r, b;
	cin >> r >> b;
	int rr = 0, bb = 0;
	for (int i = 0; i < r.size(); i++) {
		if (r[i] > b[i]) rr++;
		else if (r[i] < b[i]) bb++;
	}
	if (rr > bb) cout << "RED";
	else if (rr == bb) cout << "EQUAL";
	else cout << "BLUE";
	cout << endl;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) solve();
}
