#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

int N, D;
int A[2'00000 + 5] = { 0, };
multiset<int> diffs;

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		diffs.clear();
		scanf("%d %d", &N, &D);

		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &A[i]);
			diffs.insert(A[i] - A[i - 1] - 1);
		}

		int ans = -1;

		for (int i = 1; i <= N; i++)
		{
			diffs.erase(diffs.find(A[i] - A[i - 1] - 1));
			if (i != N)
			{
				diffs.erase(diffs.find(A[i + 1] - A[i] - 1));
				diffs.insert(A[i + 1] - A[i - 1] - 1);
			}

			int mx = *diffs.rbegin();
			int smallOne = (mx - 1) / 2;
			int largeOne = mx - smallOne;

			diffs.erase(diffs.find(mx));
			diffs.insert(smallOne);
			diffs.insert(largeOne);

			ans = max(ans, *diffs.begin());

			diffs.erase(diffs.find(largeOne));
			diffs.erase(diffs.find(smallOne));
			diffs.insert(mx);

			if (i != N && A[N] != D)
			{
				diffs.insert(D - A[N] - 1);
				ans = max(ans, *diffs.begin());
				diffs.erase(diffs.find(D - A[N] - 1));
			}
			else if(i == N)
			{
				diffs.insert(D - A[N - 1] - 1);
				ans = max(ans, *diffs.begin());
				diffs.erase(diffs.find(D - A[N - 1] - 1));
			}

			diffs.insert(A[i] - A[i - 1] - 1);
			if (i != N)
			{
				diffs.insert(A[i + 1] - A[i] - 1);
				diffs.erase(diffs.find(A[i + 1] - A[i - 1] - 1));
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
