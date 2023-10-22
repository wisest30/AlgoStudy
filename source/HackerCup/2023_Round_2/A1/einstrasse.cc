#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

string field[20];
int mark[20][20];
int row, col;
vector<pii> groups[400];
set<pii> markers[400];

void dfs(int x, int y, int g_id) {
	const int dx[] = { +1, -1, +0, +0 };
	const int dy[] = { +0, +0, +1, -1 };
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
			if (mark[nx][ny] == -1) {
				if (field[nx][ny] == 'W') {
					mark[nx][ny] = g_id;
					groups[g_id].push_back(make_pair(nx, ny));
					dfs(nx, ny, g_id);
				}
			}
			if (field[nx][ny] == '.') {
				markers[g_id].insert(make_pair(nx, ny));
			}
		}
	}
}

void solve() {
	cin >> row >> col;
	memset(mark, -1, sizeof(mark));
	for (int i = 0; i < row; i++) {
		cin >> field[i];
	}
	int group_id = -1;

	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			if (mark[x][y] == -1 && field[x][y] == 'W') {
				group_id++;
				mark[x][y] = group_id;
				groups[group_id].push_back(make_pair(x, y));
				dfs(x, y, group_id);
				if (markers[group_id].size() == 1) {
					for (int i = 0; i <= group_id; i++) {
						groups[i].clear();
						markers[i].clear();
					}
					cout << "YES\n";
					return;
				}
			}
		}
	}
	for (int i = 0; i <= group_id; i++) {
		groups[i].clear();
		markers[i].clear();
	}
	cout << "NO\n";

	return;
}
int main() {
	freopen("output.txt", "wt", stdout);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}
