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
ll A[10], B[MAXN];
int note_set[MAXN];
int unique_note;
bool lazy_check[6 * MAXN];
 
void add(int idx) {
	if (++note_set[idx] == 1) ++unique_note;
}
 
void remove(int idx) {
	if (--note_set[idx] == 0) --unique_note;
}
 
struct e {
	ll fret;
	int note_idx;
	int id;
 
	e(ll a_fret, int a_note_idx, int a_id) {
		fret = a_fret;
		note_idx = a_note_idx;
		id = a_id;
	}
 
	bool operator<(const e& rhs) const {
		if (fret == rhs.fret) {
			return id < rhs.id;
		}
		return fret < rhs.fret;
	}
};
 
int main()
{
	int i, j;
	for (i = 1; i <= 6; ++i) {
		scanf("%lld", &A[i]);
	}
 
	scanf("%d", &N);
	vector<e> vec;
	for (i = 1; i <= N; ++i) {
		scanf("%d", &B[i]);
		for (j = 1; j <= 6; ++j) {
			vec.push_back(e(B[i] - A[j], i, (j - 1) * N + i));
		}
	}
	sort(all(vec));
 
	priority_queue<pair<ll, int>> max_pq;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> min_pq;
	
	i = j = 0;
	ll ans = LINF;
 
	while (true) {
 
		while (i < vec.size() && unique_note < N) {
			add(vec[i].note_idx);
			min_pq.push({ vec[i].fret, vec[i].id });
			max_pq.push({ vec[i].fret, vec[i].id });
			++i;
		}
		if (unique_note < N) break;
		
		while (j < vec.size() && unique_note == N) {
			remove(vec[j].note_idx);
			lazy_check[vec[j].id] = true;
			if (unique_note < N) {
				add(vec[j].note_idx);
				lazy_check[vec[j].id] = false;
				break;
			}
			++j;
		}
		while (lazy_check[min_pq.top().second]) {
			min_pq.pop();
		}
		while (lazy_check[max_pq.top().second]) {
			max_pq.pop();
		}
		ll mini = min_pq.top().first;
		ll maxi = max_pq.top().first;
		ans = min(ans, maxi - mini);
		remove(vec[j].note_idx);
		lazy_check[vec[j].id] = true;
		++j;
	}
 
	printf("%lld\n", ans);
	return 0;
}