#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <cmath>
#include <time.h>
#include <unordered_set>
#include <unordered_map>
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define PI 3.14159265
#define RAND (rand()*rand())
#define MAX(x, y) ((x) > (y) ? (x):(y)) 
#define MIN(x, y) ((x) > (y) ? (y):(x))
#define ABS(x) ((x) > 0 ? ((x) : -(x)))
#define CEIL(x, y) (((x) + (y) - 1)/(y))
#define all(x) (x).begin(), (x).end()
using namespace std;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
ll gcd(ll a, ll b) { if (b == 0LL) return a; return gcd(b, a % b); }
ll binpow(ll a, ll b) { ll res = 1ll; while (b) { if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1; }return res; }
int N, M, K, Q;
 
int rows[510][510];
 
void solve(int testNum) {
	int i, j, x;
	scanf("%d%d", &N, &M);
	vector<int> at_row(N * M + 3);
	for (i = 0; i < N; ++i) {
		for (j = 0; j < M; ++j) {
			scanf("%d", &rows[i][j]);
			at_row[rows[i][j]] = i;
		}
	}
 
	vector<int> orders;
	for (j = 0; j < M; ++j) {
		for (i = 0; i < N; ++i) {
			scanf("%d", &x);
			if (j == 0) {
				orders.push_back(at_row[x]);
			}
		}
	}
 
	for (int order : orders) {
		int* row = rows[order];
		for (i = 0; i < M; ++i) {
			printf("%d ", row[i]);
		}
		printf("\n");
	}
	return;
}
 
int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		solve(t);
	}
	return 0;
}