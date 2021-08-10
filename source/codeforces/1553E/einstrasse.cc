#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl '\n'

int chk[300005];
int p[300005];
vector<int> adj[300005];
bool visit[300005];
void dfs(int v) {
	for (int a : adj[v]) {
		if (visit[a] == false) {
			visit[a] = true;
			dfs(a);
		}
	}
}
bool ok(int k, int n, int m) {
	// permutation에 대해서 graph로 모델링 한 뒤
	// n에서 component 개수만큼 빼면 필요한 swap 횟수가 나온다.
	memset(visit, 0, sizeof(bool) * n);
	for (int i = 0; i < n; i++) {
		adj[i].clear();
	}
	for (int i = 0; i < n; i++) {
		int a = (i - k + n) % n;
		int b = p[i];
		adj[a].push_back(b);
	}
	int compn = 0;
	for (int i = 0; i < n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			dfs(i);
			compn++;
		}
	}
	return n - compn <= m;
}
void solve() {
	vector<int> ans;
	int n, m;
	cin >> n >> m;
	memset(chk, 0, sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		cin >> p[i]; p[i]--;
		int v = (i - p[i] + n) % n;
		chk[v]++;
	}
	// in place에 제대로 끼어있는 녀석이 n-2m개 이상인지 확인
	for (int i = 0; i < n && ans.size() < 3; i++) {
		if (chk[i] >= n - 2 * m) {
			ans.push_back(i);
		}
	}
	// 실제 swap으로 만들 수 있는지 다시 확인.
	vector<int> realans;
	for (int i = 0; i < ans.size(); i++) {
		if (ok(ans[i], n, m)) {
			realans.push_back(ans[i]);
		}
	}
	cout << realans.size() << ' ';
	for (int a : realans) {
		cout << a << ' ';
	}
	cout << endl;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) solve();
}
