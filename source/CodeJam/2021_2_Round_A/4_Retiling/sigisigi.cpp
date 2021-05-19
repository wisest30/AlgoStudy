#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll TCC;
ll R, C, F, S;
ll sta[11][11];
ll omap[11][11];//1==need -1==lose
vector<int>need_city;
vector<int>lose_city;
int capa[102][102];
int price[102][102];
int flow[102][102];
const int Start = 100;
const int Sink = 101;
vector<vector<int>>adj;
ll chg = 0;
ll n_need = 0;
ll l_need = 0;

void sol2() {
	int org_chg = chg;
	ll total_price = 0;
	while (1) {
		int prev[102], dist[102];
		int visited[102];
		queue<int>Q;
		fill(prev, prev + 102, -1);
		fill(dist, dist + 102, INT_MAX);
		fill(visited, visited + 102, 0);
		dist[Start] = 0;
		visited[Start] = 1;
		Q.push(Start);
		while (!Q.empty()) {
			int current_city = Q.front();
			Q.pop();
			visited[current_city] = 0;
			for (int next_city : adj[current_city]) {
				if (capa[current_city][next_city] - flow[current_city][next_city] > 0 &&
					dist[next_city] > dist[current_city] + price[current_city][next_city]) {
					dist[next_city] = dist[current_city] + price[current_city][next_city];
					prev[next_city] = current_city;
					if (visited[next_city] == 0) {
						Q.push(next_city);
						visited[next_city] = 1;
					}
				}
			}
		}
		if (prev[Sink] == -1)break;
		
		ll prevprice = total_price;
		for (int i = Sink; i != Start; i = prev[i]) {
			total_price += price[prev[i]][i];
			flow[prev[i]][i] += 1;
			flow[i][prev[i]] += -1;
			
		}
		if (total_price - prevprice > F * 2) {
			total_price = prevprice += F * 2;

		}
		
		chg -= 2;

	}
	total_price += 1LL*chg * F ;
	//cout << "FLIP :" << chg << ", SWAP :,"<< (org_chg-chg)/2 <<" ";
	cout << total_price << endl;

}
ll calc_wei(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y2 - y1);
}
void sol() {
	char t;
	chg = 0;
	n_need = 0;
	l_need = 0;
	need_city.clear();
	lose_city.clear();
	adj.clear();
	adj.resize(102);
	cin >> R >> C >> F >> S;

	fill(&flow[0][0], &flow[101][102], 0);
	fill(&price[0][0], &price[101][102], 0);
	fill(&capa[0][0], &capa[101][102], 0);
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
		cin >> t;
		if (t == 'M')
			sta[i][j] = 1;
		else
			sta[i][j] = 0;
	}
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
		cin >> t;
		if (t == 'M') {
			if (sta[i][j] == 0) {
				need_city.push_back(i * 10 + j);
				chg++;
				n_need++;
				omap[i][j] = 1;
			}
			else
				omap[i][j] = 0;
		}
		else {
			if (sta[i][j] == 1) {
				lose_city.push_back(i * 10 + j);
				l_need++;
				chg++;
				omap[i][j] = -1;
			}
			else
				omap[i][j] = 0;
		}
	}

	for (int i = 0; i < lose_city.size();i++) {
		for (int j = 0; j < need_city.size(); j++) {
			ll wei = calc_wei(lose_city[i] / 10, lose_city[i] % 10, need_city[j] / 10, need_city[j] % 10)*S;
			if (wei >= F * 2)continue;
			price[lose_city[i]][need_city[j]] = wei;
			price[need_city[j]][lose_city[i]] = -wei;
			capa[lose_city[i]][need_city[j]] = 1;
			adj[lose_city[i]].push_back(need_city[j]);
			adj[need_city[j]].push_back(lose_city[i]);
		}
	}
	ll cost = 0;
	for (int i = 0; i < lose_city.size(); i++) {
		adj[Start].push_back(lose_city[i]);
		adj[lose_city[i]].push_back(Start);
		capa[Start][lose_city[i]] = 1;
		//price[Start][lose_city[i]] = 0;
	}
	for (int i = 0; i < need_city.size(); i++) {
		adj[Sink].push_back(need_city[i]);
		adj[need_city[i]].push_back(Sink);
		capa[need_city[i]][Sink] = 1;
		//price[need_city[i]][Sink] = 0;
	}
	sol2();


}
int main() {
	//freopen("test_set_2/ts2_input.txt", "rt", stdin);
	cin >> TCC;
	for (int i = 0; i < TCC; i++) {
		cout << "Case #" << i + 1 << ": ";
		sol();
	}


}
