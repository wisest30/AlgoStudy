#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
void solve() {
	int n, m;
	vector<int> garo[505];
	map<int, int> mm;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int v;
			cin >> v;
			if (j == 0) mm[v] = i; //v가 포함된건 i번째 row이다.
			garo[i].push_back(v);
		}
	}
	vector<int> sero[505];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int v;
			cin >> v;
			sero[i].push_back(v);
		}
	}
	vector<int> order;
	for (int i = 0; i < m; i++) {
		if (mm.find(sero[i][0]) != mm.end()) {
			//here!
			for (int pivot : sero[i]) {
				order.push_back(mm[pivot]);
			}
			break;
		}
	}
	for (int row : order) {
		for (int v : garo[row]) {
			cout << v << ' ';
		}
		cout << endl;
	}
	return;
}
 
int main() {
 
	int tc;
	cin >> tc;
	while (tc--) solve();
	return 0;
}