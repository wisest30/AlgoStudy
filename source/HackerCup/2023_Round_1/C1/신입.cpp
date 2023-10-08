#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <algorithm>
#include <vector>

using namespace std;

int len;
char input[4'000'000 + 5];

int queries[4'000'000 + 5];

void solve()
{
	scanf("%d", &len);
	scanf("%s", input + 1);

	int Q;

	scanf("%d", &Q);

	for (int i = 0; i < Q; i++) scanf("%d", &queries[i]);
	sort(queries, queries + Q);

	queries[Q] = len + 1;
	
	int prv = queries[0];
	int cnt = 1;

	for (int i = 1; i <= Q; i++)
	{
		if (queries[i] == prv) cnt++;
		else
		{
			if (cnt % 2)
			{
				for (int j = prv; j <= len; j += prv) input[j] = (1 - (input[j] - '0')) + '0';
			}
			cnt = 1;
		}
		prv = queries[i];
	}

	int ans = 0;

	for (int i = 1; i <= len; i++)
	{
		if (input[i] == '1')
		{
			ans++;
			for (int j = i; j <= len; j += i) input[j] = (1 - (input[j] - '0')) + '0';
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

	for (int tc = 1; tc <= T; ++tc)
	{
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}
