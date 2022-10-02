#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

typedef long long ll;
using namespace std;

constexpr int MAXN = 1'000'000 + 5;

int N;
int arr[MAXN];
ll totalFenwick[MAXN];
ll sumFenwick[3][MAXN];
ll cntFenwick[3][MAXN];

void upd(ll *fenwick, int idx, int diff)
{
	for(;idx<=N;idx+=(idx&(-idx))) fenwick[idx] = (fenwick[idx] + diff);
}

ll getVal(ll *fenwick, int idx)
{
	ll ret = 0;
	for (; idx; idx -= (idx&(-idx))) ret = (ret + fenwick[idx]);
	return ret;
}

void solve()
{
	memset(totalFenwick, 0, sizeof(totalFenwick));
	memset(sumFenwick, 0, sizeof(sumFenwick));
	memset(cntFenwick, 0, sizeof(cntFenwick));

	int Q;
	int cnt[3]{};

	ll ans = 0;

	scanf("%d %d", &N, &Q);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
		cnt[arr[i]]++;
		upd(totalFenwick, i, arr[i]);
		upd(sumFenwick[arr[i]], i, i);
		upd(cntFenwick[arr[i]], i, 1);
	}

	while (Q--)
	{
		int X, Y, Z;

		scanf("%d %d %d", &X, &Y, &Z);

		cnt[arr[X]]--;
		upd(totalFenwick, X, -arr[X]);
		upd(sumFenwick[arr[X]], X, -X);
		upd(cntFenwick[arr[X]], X, -1);

		arr[X] = Y;

		cnt[arr[X]]++;
		upd(totalFenwick, X, arr[X]);
		upd(sumFenwick[arr[X]], X, X);
		upd(cntFenwick[arr[X]], X, 1);

		ll total = cnt[1] + 2LL * cnt[2];
		ll untilZ = getVal(totalFenwick, Z);

		if (total % 2)
		{
			ans += -1;
			continue;
		}

		ll target = total / 2;

		int from = 1;
		int to = 2;
		int neededCnt = target - untilZ;

		if (neededCnt == 0) continue;

		if (target < untilZ)
		{
			swap(from, to);
			neededCnt = -neededCnt;
		}

		int toEdLow = Z + 1, toEdHigh = N, toEdAns = -1;
		int fromStLow = 1, fromStHigh = Z, fromStAns = -1;

		while (toEdLow <= toEdHigh)
		{
			int mid = (toEdLow + toEdHigh) / 2;

			int edCnt = getVal(cntFenwick[to], mid) - getVal(cntFenwick[to], Z);

			if (edCnt == neededCnt)
			{
				toEdAns = mid;
				break;
			}
			else if (edCnt > neededCnt) toEdHigh = mid - 1;
			else toEdLow = mid + 1;
		}
		while (fromStLow <= fromStHigh)
		{
			int mid = (fromStLow + fromStHigh) / 2;

			int stCnt = getVal(cntFenwick[from], Z) - getVal(cntFenwick[from], mid - 1);

			if (stCnt == neededCnt)
			{
				fromStAns = mid;
				break;
			}
			else if (stCnt > neededCnt) fromStLow = mid + 1;
			else fromStHigh = mid - 1;
		}

		if (toEdAns == -1 || fromStAns == -1)
		{
			ans += -1;
			continue;
		}

		ans += getVal(sumFenwick[to], toEdAns) - getVal(sumFenwick[to], Z) 
			- (getVal(sumFenwick[from], Z) - getVal(sumFenwick[from], fromStAns - 1));
	}

	printf("%lld\n", ans);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc)
	{
		printf("Case #%d: ", tc);
		solve();
	}

	return 0;
}
