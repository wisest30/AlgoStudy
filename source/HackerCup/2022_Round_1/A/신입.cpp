#include <stdio.h>

typedef long long ll;
using namespace std;

constexpr int MAXN = 5'000000;
constexpr ll MOD[2] = { 1'000'000'007LL, 998'244'353LL };
constexpr ll PRIME = 29LL;

constexpr int MOD_SZ = 2;

struct Hash
{
	ll HashVal[MOD_SZ];
};

bool operator==(const Hash &a, const Hash &b)
{
	for (int i = 0; i < MOD_SZ; i++)
	{
		if (a.HashVal[i] != b.HashVal[i]) return false;
	}
	return true;
}

ll PRIMES[MAXN + 5][2] = { {1LL, 1LL}, };
int A[MAXN + 5], B[MAXN + 5];

void init()
{
	for (int i = 1; i <= MAXN; i++)
	{
		for (int j = 0; j < MOD_SZ; j++)
		{
			PRIMES[i][j] = (PRIMES[i - 1][j] * PRIME) % MOD[j];
		}
	}
}

void solve()
{
	int N, K;

	scanf("%d %d", &N, &K);

	Hash A_HASH{};
	Hash B_HASH{};

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		for (int j = 0; j < MOD_SZ; j++) A_HASH.HashVal[j] = (A_HASH.HashVal[j] * PRIME + A[i]) % MOD[j];
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &B[i]);
		for (int j = 0; j < MOD_SZ; j++) B_HASH.HashVal[j] = (B_HASH.HashVal[j] * PRIME + B[i]) % MOD[j];
	}

	bool found = false;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < MOD_SZ; j++)
		{
			A_HASH.HashVal[j]
				= ((A_HASH.HashVal[j] * PRIME) % MOD[j] + MOD[j] - (A[i] * PRIMES[N][j]) % MOD[j] + A[i]) % MOD[j];
		}

		if (A_HASH == B_HASH)
		{
			int st = i + 1;

			bool valid = true;

			for (int j = 0; j < N; j++)
			{
				if (A[(st + j) % N] != B[j])
				{
					valid = false;
					break;
				}
			}

			if (valid)
			{
				found = true;
				break;
			}
		}

		if (found) break;
	}

	if (!found)
	{
		printf("NO\n");
		return;
	}

	if (N > 2)
	{

		if (K > 1) printf("YES\n");
		else if (K == 1) {
			bool allSame = true;

			for (int i = 0; i < N; i++)
			{
				if (A[i] != B[i])
				{
					printf("YES\n");
					return;
				}
				if (A[i] != A[0]) allSame = false;
			}

			if(!allSame) printf("NO\n");
			else printf("YES\n");
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				if (A[i] != B[i])
				{
					printf("NO\n");
					return;
				}
			}
			printf("YES\n");
		}
	}
	else
	{
		if (K % 2 == 0)
		{
			if (A[0] == B[0] && A[1] == B[1]) printf("YES\n");
			else printf("NO\n");
		}
		else
		{
			if (A[0] == B[1] && A[1] == B[0]) printf("YES\n");
			else printf("NO\n");
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;

	scanf("%d", &T);

	init();

	for (int tc = 1; tc <= T; ++tc)
	{
		printf("Case #%d: ", tc);
		solve();
	}

	return 0;
}
