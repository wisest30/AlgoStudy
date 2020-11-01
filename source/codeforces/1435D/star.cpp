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
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define CEIL(x, y) (((x) + (y) - 1)/(y))
#define all(x) (x).begin(), (x).end()
using namespace std;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
const double eps = 1e-7;
ll gcd(ll a, ll b) { if (b == 0LL) return a; return gcd(b, a % b); }
ll binpow(ll a, ll b) { ll res = 1ll; while (b) { if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1; }return res; }
int N, M, K, Q, T;
int L[MAXN];
int vis[MAXN];
 
int main()
{
	int i, j, c, x;
	char op[5];
	vector<pair<int, int>> seq;
	c = 0;
	scanf("%d", &N);
	for (i = 1; i <= 2 * N; ++i) {
		scanf("%s", op);
		if (op[0] == '+') {
			++c;
		}
		else {
			scanf("%d", &x);
			seq.push_back({ x, c });
			c = 0;
		}
	}
	int sum = 0;
	for (i = 0; i < N; ++i) {
		sum += seq[i].second;
		if ((i + 1) > sum) {
			printf("NO\n");
			return 0;
		}
	}
 
	vector<pair<int, int>> stk;
	stk.push_back({ 0, INF });
	for (i = 0; i < N; ++i) {
		x = seq[i].first;
		c = seq[i].second;
		while (stk.back().second < x) stk.pop_back();
		L[x] = stk.back().first;
		stk.push_back({ i + 1, x });
	}
 
	vector<pair<int, int>> pairs;
	for (i = 0; i < N; ++i) {
		x = seq[i].first;
		pairs.push_back({ L[x], x });
		pairs.push_back({ i + 1, -x });
	}
	sort(all(pairs));
 
	j = 0;
	priority_queue<int, vector<int>, greater<int>> min_pq;
	vector<int> answer;
	for (i = 0; i < 2 * N; ++i) {
		x = pairs[i].second;
 
		if (x < 0) {
			c = seq[j].second;
			++j;
 
			if (min_pq.size() < c) {
				printf("NO\n");
				return 0;
			}
 
			while (c) {
				answer.push_back(min_pq.top());
				vis[min_pq.top()] = true;
				min_pq.pop();
				--c;
			}
 
			if (!vis[-x]) {
				printf("NO\n");
				return 0;
			}
		}
		else {
			min_pq.push(x);
		}
	}
	printf("YES\n");
	for (i = 0; i < N; ++i) printf("%d ", answer[i]);
	return 0;
}