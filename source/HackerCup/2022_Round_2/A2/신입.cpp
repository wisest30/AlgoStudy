#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

typedef long long ll;
using namespace std;

constexpr int MOD_SZ = 3;
constexpr int SZ = 1'000'000 + 5;
constexpr ll PRIME = 1'000'003;
constexpr ll MOD[MOD_SZ] = { 998'244'353, 1'000'000'007, 1'000'000'009 };

int N;
int arr[SZ];
ll fenwick[SZ][MOD_SZ];
ll PRIMES[SZ][MOD_SZ];
set<ll> PRIMES_SET[MOD_SZ];

void init()
{
	for (int j = 0; j < MOD_SZ; j++) PRIMES[0][j] = 1;

	for (int i = 1; i < SZ; i++)
	{
		for (int j = 0; j < MOD_SZ; j++)
		{
			PRIMES[i][j] = (PRIMES[i - 1][j] * PRIME) % MOD[j];
			PRIMES_SET[j].insert(PRIMES[i][j]);
		}
	}
}

void upd(int idx, int num, int diff)
{
	for (; idx <= N; idx += (idx&(-idx)))
	{
		for (int i = 0; i < MOD_SZ; i++) fenwick[idx][i] = (fenwick[idx][i] + diff * PRIMES[num][i] + MOD[i]) % MOD[i];
	}
}

ll getUntil(int idx, int MOD_IDX)
{
	ll ret = 0;
	for (; idx; idx -= (idx&(-idx))) ret = (ret + fenwick[idx][MOD_IDX]) % MOD[MOD_IDX];
	return ret;
}

void solve()
{
	memset(fenwick, 0, sizeof(fenwick));

	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
		upd(i, arr[i], 1);
	}

	int Q;
	int ans = 0;

	scanf("%d", &Q);

	while (Q--)
	{
		int cmd;
		
		scanf("%d", &cmd);

		if (cmd == 1)
		{
			int idx, num;

			scanf("%d %d", &idx, &num);

			upd(idx, arr[idx], -1);
			upd(idx, num, 1);
			
			arr[idx] = num;
		}
		else
		{
			int l, r;

			scanf("%d %d", &l, &r);

			if ((r - l) % 2) continue;

			int mid = (l + r) / 2;

			bool valid = true;

			for (int j = 0; j < MOD_SZ; j++)
			{
				ll rightHalf = (getUntil(r, j) - getUntil(mid - 1, j) + MOD[j]) % MOD[j];
				ll leftHalf = (getUntil(mid - 1, j) - getUntil(l - 1, j) + MOD[j]) % MOD[j];

				ll diff = (rightHalf - leftHalf + MOD[j]) % MOD[j];

				if (!PRIMES_SET[j].count(diff))
				{
					valid = false;
					break;
				}
			}

			if (valid)
			{
				ans++;
				continue;
			}

			valid = true;

			for (int j = 0; j < MOD_SZ; j++)
			{
				ll rightHalf = (getUntil(r, j) - getUntil(mid, j) + MOD[j]) % MOD[j];
				ll leftHalf = (getUntil(mid, j) - getUntil(l - 1, j) + MOD[j]) % MOD[j];

				ll diff = (leftHalf - rightHalf + MOD[j]) % MOD[j];

				if (!PRIMES_SET[j].count(diff))
				{
					valid = false;
					break;
				}
			}

			if (valid)
			{
				ans++;
				continue;
			}
		}
	}

	printf("%d\n", ans);
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
