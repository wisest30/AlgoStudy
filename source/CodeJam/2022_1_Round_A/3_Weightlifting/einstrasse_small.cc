#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

int dist(vector<char>& src, vector<char>& dst) {
	int prefix = 0;
	while (prefix < src.size() && prefix < dst.size() && src[prefix] == dst[prefix]) prefix++;
	return src.size() + dst.size() - prefix - prefix;
}

void solve() {
	int E, W;
	int X[11][3];
	int nodenum[17];
	vector<vector<char>> arrange;
	arrange.clear();
	cin >> E >> W;
	if (E > 10 || W > 3) return; //surrender
	memset(nodenum, 0, sizeof(nodenum));
	for (int i = 0; i < E; i++) {
		for (int j = 0; j < W; j++) {
			cin >> X[i][j];
		}
	}
	arrange.push_back(vector<char>());
	nodenum[1]++;
	for (int e = 0; e < E; e++) {
		vector<char> arr;
		arr.clear();
		for (int i = 0; i < W; i++) {
			for (int j = 0; j < X[e][i]; j++) {
				arr.push_back('A' + i);
			}
		} //init
		do {
			arrange.push_back(arr);
			nodenum[e+2]++;
		} while (next_permutation(arr.begin(), arr.end()));
	}
	arrange.push_back(vector<char>());
	nodenum[E + 2]++;
	for (int i = 1; i <= E + 2; i++) {
		nodenum[i] += nodenum[i - 1];
	}
	vector<vector<pii>> edges(arrange.size(), vector<pii>());
	vector<int> distance(arrange.size(), INT_MAX);
	// dest node num, length
	int goal = nodenum[E + 2] - 1;
	for (int k = 0; k <= E; k++) {
		for (int src = nodenum[k]; src < nodenum[k + 1]; src++) {
			for (int dst = nodenum[k + 1]; dst < nodenum[k + 2]; dst++) {
				edges[src].push_back(make_pair(dst, dist(arrange[src], arrange[dst])));
			}
		}
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0, 0)); //total cost, current node
	while (pq.size()) {
		auto cur = pq.top(); pq.pop();
		if (cur.second == goal) {
			cout << distance[goal] << endl;
			return;
		}
		for (auto next : edges[cur.second]) {
			int new_cost = cur.first + next.second;
			int next_node = next.first;
			if (distance[next_node] > new_cost) {
				pq.push(make_pair(new_cost, next_node));
				distance[next_node] = new_cost;
			}
		}
	}
	return;
}
int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}
