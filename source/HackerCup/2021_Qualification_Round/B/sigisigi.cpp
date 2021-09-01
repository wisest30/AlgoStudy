#include <bits/stdc++.h>
#define INPUT 

using namespace std;
int tc;

void solve() {
	string input;
	int n;
	cin >> n;
	vector<vector<char>> grid(n,vector<char>(n));
	for (int i = 0; i < n; i++) {
		string in;
		cin >> in;
		for (int j = 0; j < in.size(); j++) {
			grid[i][j] = in[j];
		}
	}
	map<int, int>ret;
	for (int i = 0; i < n; i++) {
		int rowIter = 0;
		int colIter = 0;
		for (int j = 0; j < grid.size(); j++) {
			if (grid[i][j] == 'X')continue;
			else if (grid[i][j] == '.') {
				rowIter++;
			}
			else if (grid[i][j] == 'O') {
				rowIter = -1;
				break;
			}
		}
		for (int j = 0; j < grid.size(); j++) {
			if (grid[j][i] == 'X')continue;
			else if (grid[j][i] == '.') {
				colIter++;
			}
			else if (grid[j][i] == 'O') {
				colIter = -1;
				break;
			}
		}
		if (rowIter >= 0)
			ret[rowIter]++;
		if (colIter >= 0) {
			ret[colIter]++;
		}
	}
	if (ret.size() == 0)cout << "Impossible" << endl;
	else if (ret.begin()->first == 1) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				 if (grid[i][j] == '.') {
					 bool rcheck = true;
					 bool ccheck = true;
					 for (int k = 0; k < n; k++) {
						 if (j == k)continue;
						 if (grid[i][k] != 'X')
							 ccheck = false;
					 }
					 for (int k = 0; k < n; k++) {
						 if (i == k)continue;
						 if (grid[k][j] != 'X')
							 rcheck = false;
					 }
					 if (ccheck || rcheck)cnt++;
				}
			}
		}
		cout << 1 << " " << cnt << endl;
	}
	else cout << ret.begin()->first << " " << ret.begin()->second << endl;





}
int main() {
#ifdef INPUT
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cout << "Case #" << i << ": ";
		solve();
		cout<< endl;
	}
}
