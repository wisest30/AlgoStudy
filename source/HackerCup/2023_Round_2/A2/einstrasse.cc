#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

string field[3001];
int mark[3001][3001];
int row, col;
int groups[9000005];
int marker_cnt[9000005];
pii marker[9000005];
map<pii, int> eats;

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
					groups[g_id]++;
					dfs(nx, ny, g_id);
				}
			}
			if (field[nx][ny] == '.') {
				if (marker[g_id].first != nx || marker[g_id].second != ny) {
					marker_cnt[g_id]++;
				}
				marker[g_id].first = nx;
				marker[g_id].second = ny;
			}
		}
	}
}

void solve() {
	int ans = 0;
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

				groups[group_id]++;
				dfs(x, y, group_id);
				if (marker_cnt[group_id] == 1) {
					pii target = marker[group_id];
					if (eats.count(target)) {
						eats[target] = eats[target] + groups[group_id];
					}
					else {
						eats[target] = groups[group_id];
					}
				}
			}
		}
	}
	for (int i = 0; i <= group_id; i++) {
		groups[i] = 0;
		marker_cnt[i] = 0;
		marker[i].first = -1;
		marker[i].second = -1;
	}
	for (auto v : eats) {
		ans = max(ans, v.second);
	}
	eats.clear();
	cout << ans << endl;

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
