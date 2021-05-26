#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
double X,W,E;
double dp[61][61][61];
int pprev[61][61][61];

void sol() {
	
	cin >> W >> E;
	fill(&dp[0][0][0], &dp[60][60][61], -1);
	dp[0][0][1] = dp[0][1][0] = dp[1][0][0] = W / 3 + E / 3;
	pprev[0][0][1] = 3;
	pprev[0][1][0] = 2;
	pprev[1][0][0] = 1;
	int maxr, maxs, maxp, maxv=-1;
	for (int N = 2; N <= 60; N++) { 
		for (int r = N; r >= 0; r--) { 
			for (int s = N - r; s >= 0; s--) { 
				for (int p = N - r-s; p >= 0;p--) {
					double & ret = dp[r][s][p];
					if (ret > -0.5)continue;
					double rsp = (r + s + p - 1);

					if (r > 0 && ret < dp[r - 1][s][p] + (W * p + E * s) / rsp) {
						ret = dp[r - 1][s][p] + (W * p + E * s) / rsp;
						pprev[r][s][p] = 1;
					}
					if (s > 0 && ret < dp[r ][s-1][p] + (W * r + E * p) / rsp) {
						ret = dp[r][s - 1][p] + (W * r + E * p) / rsp;
						pprev[r][s][p] = 2;
					}
					if (p > 0 && ret < dp[r][s][p-1] + (W * s + E * r) / rsp) {
						ret = dp[r][s ][p-1] + (W * s + E * r) / rsp;
						pprev[r][s][p] = 3;
					}
					if (N == 60 && maxv < ret) {
						maxv = ret;
						maxr = r, maxs = s, maxp = p;
					}
				}
			}
		}
	}
	//cout << maxv << endl;
	int t = pprev[maxr][maxs][maxp];
	char ret[61];
	ret[60] = 0;
	for (int i = 0; i < 60; i++) {
		int t = pprev[maxr][maxs][maxp];
		if (t == 1)ret[59-i]='R', maxr--;
		else if (t == 2)ret[59 - i] = 'S', maxs--;
		else ret[59 - i] = 'P', maxp--;
	}


	cout << ret << endl;
	
	
}


int main() {
	int T;
	cin >> T;
	cin >> X;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ": ";
		sol();
	}
}
