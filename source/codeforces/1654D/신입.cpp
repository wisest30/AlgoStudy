#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

typedef long long ll;

constexpr ll MOD = 998'244'353;
constexpr int MAXN = 2'00000;
constexpr int PRIME_SIZE = 17985;

vector<int> primes;
int primeIdxMap[MAXN + 5];
bool isNotPrime[MAXN + 5];

ll rev[MAXN + 5];

int cur[PRIME_SIZE];
int lcm[PRIME_SIZE];

struct Edge
{
	int node;
	int div;
	int mul;
};

int N;
vector<Edge> adj[MAXN + 5];

ll totalSum;

ll myPow(ll base, int exponent)
{
	ll ret = 1;

	while (exponent)
	{
		if (exponent & 1) ret = (ret * base) % MOD;
		base = (base * base) % MOD;
		exponent /= 2;
	}

	return ret;
}

void init()
{
	for (int i = 2; i <= MAXN; i++)
	{
		if (!isNotPrime[i])
		{
			primeIdxMap[i] = (int)primes.size();
			primes.push_back(i);

			for (ll j = 1LL * i * i; j <= MAXN; j += i) isNotPrime[j] = true;
		}
	}

	for (int i = 1; i <= MAXN; i++) rev[i] = myPow(1LL * i, MOD - 2);
}

void calcTotalSum(int cur, int prv, ll curVal)
{
	totalSum = (totalSum + curVal) % MOD;

	for (auto& nxt : adj[cur])
	{
		if (nxt.node == prv) continue;
		calcTotalSum(nxt.node, cur, (((curVal*nxt.mul) % MOD)*rev[nxt.div]) % MOD);
	}
}

void primeFactorization(int num, bool isDiv)
{
	for (int i = 0; 1LL * primes[i] * primes[i] <= num; i++)
	{
		while (num%primes[i] == 0)
		{
			num /= primes[i];
			if (isDiv) cur[i]++;
			else cur[i]--;
		}

		if (isDiv)
		{
			if (cur[i] > lcm[i])
			{
				totalSum = (totalSum * myPow(primes[i], cur[i] - lcm[i])) % MOD;
				lcm[i] = cur[i];
			}
		}
	}

	if (num != 1)
	{
		int idx = primeIdxMap[num];
		
		if (isDiv) cur[idx]++;
		else cur[idx]--;

		if (isDiv)
		{	
			if (cur[idx] > lcm[idx])
			{
				totalSum = (totalSum * myPow(primes[idx], cur[idx] - lcm[idx])) % MOD;
				lcm[idx] = cur[idx];
			}
		}
	}
}

void calcLCM(int cur, int prv)
{
	for (auto& nxt : adj[cur])
	{
		if (nxt.node == prv) continue;

		primeFactorization(nxt.mul, false);
		primeFactorization(nxt.div, true);

		calcLCM(nxt.node, cur);

		primeFactorization(nxt.div, false);
		primeFactorization(nxt.mul, true);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	int T;

	cin >> T;

	while (T--)
	{
		memset(lcm, 0, sizeof(lcm));
		totalSum = 0;
		cin >> N;

		for (int i = 1; i <= N; i++) adj[i].clear();
		
		for (int i = 0; i < N - 1; i++)
		{
			int u, v, x, y;

			cin >> u >> v >> x >> y;

			adj[u].push_back({ v, x, y });
			adj[v].push_back({ u, y, x });
		}

		calcTotalSum(1, 0, 1LL);
		calcLCM(1, 0);

		cout << totalSum << "\n";
	}

	return 0;
}
