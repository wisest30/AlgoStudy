#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

constexpr int SZ = 1'000000 + 5;

int arr[SZ];
int fenwick[SZ][4];
int N;

void upd(int idx, int target, int diff)
{
	for (; idx <= N; idx += (idx&(-idx))) fenwick[idx][target] += diff;
}

int getCnt(int idx, int target)
{
	int ret = 0;
	for (; idx; idx -= (idx&(-idx))) ret += fenwick[idx][target];

	return ret;
}

void solve()
{
	int Q;
	
	memset(fenwick, 0, sizeof(fenwick));

	scanf("%d %d", &N, &Q);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
		upd(i, arr[i], 1);
	}

	ll ans = 0;

	for (int i = 0; i < Q; i++)
	{
		int X, Y, Z;

		scanf("%d %d %d", &X, &Y, &Z);

		upd(X, arr[X], -1);
		arr[X] = Y;
		upd(X, arr[X], 1);

		int total[4]{};
		int untilZ[4]{};
		int afterZ[4]{};

		for (int j = 1; j <= 3; j++) total[j] = getCnt(N, j);
		for (int j = 1; j <= 3; j++)
		{
			untilZ[j] = getCnt(Z, j);
			afterZ[j] = total[j] - untilZ[j];
		}

		int totalSum = total[1] + 2 * total[2] + 3 * total[3];
		int ZSum = untilZ[1] + 2 * untilZ[2] + 3 * untilZ[3];
		int targetSum = totalSum / 2 - ZSum;

		if (totalSum % 2 == 0 && targetSum >= 0)
		{
			int temp = 0;
			int oneToThree = min({ untilZ[1], afterZ[3], (targetSum) / 2 });

			untilZ[1] -= oneToThree;
			afterZ[3] -= oneToThree;
			targetSum -= 2*oneToThree;

			temp += oneToThree;

			if (targetSum == 0)
			{
				ans += temp;
				continue;
			}

			int oneToTwo = min({ untilZ[1], afterZ[2], targetSum });

			untilZ[1] -= oneToTwo;
			afterZ[2] -= oneToTwo;
			targetSum -= oneToTwo;

			temp += oneToTwo;

			if (targetSum == 0)
			{
				ans += temp;
				continue;
			}

			int twoToThree = min({ untilZ[2], afterZ[3], targetSum });

			untilZ[2] -= twoToThree;
			afterZ[3] -= twoToThree;
			targetSum -= twoToThree;

			temp += twoToThree;

			if (targetSum == 0)
			{
				ans += temp;
				continue;
			}

			ans += -1;
			continue;
		}
		else if (totalSum % 2 == 0 && targetSum < 0)
		{
			targetSum = -targetSum;

			int temp = 0;
			int ThreeToOne = min({ untilZ[3], afterZ[1], (targetSum) / 2 });

			untilZ[3] -= ThreeToOne;
			afterZ[1] -= ThreeToOne;
			targetSum -= 2 * ThreeToOne;

			temp += ThreeToOne;

			if (targetSum == 0)
			{
				ans += temp;
				continue;
			}

			int TwoToOne = min({ untilZ[2], afterZ[1], targetSum });

			untilZ[2] -= TwoToOne;
			afterZ[1] -= TwoToOne;
			targetSum -= TwoToOne;

			temp += TwoToOne;

			if (targetSum == 0)
			{
				ans += temp;
				continue;
			}

			int ThreeToTwo = min({ untilZ[3], afterZ[2], targetSum });

			untilZ[3] -= ThreeToTwo;
			afterZ[2] -= ThreeToTwo;
			targetSum -= ThreeToTwo;

			temp += ThreeToTwo;

			if (targetSum == 0)
			{
				ans += temp;
				continue;
			}

			ans += -1;
			continue;
		}

		ans += -1;
		continue;
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
