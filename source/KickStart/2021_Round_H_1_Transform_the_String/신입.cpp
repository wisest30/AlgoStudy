#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? (-(a)) : (a))

typedef long long ll;

using namespace std;

bool used[26]{};
char S[1'00000 + 5];
char F[26 + 5];

void solve()
{
	memset(used, false, sizeof(used));

	scanf("%s", S);
	scanf("%s", F);

	for (int i = 0; F[i]; i++) used[F[i] - 'a'] = true;

	ll ans = 0;

	for (int i = 0; S[i]; i++)
	{
		int curMn = 26;

		for (int j = 0; j < 26; j++)
		{
			if (!used[j]) continue;
			int localMin = min(ABS(j - (S[i] - 'a')), 26 - ABS(j - (S[i] - 'a')));
			curMn = min(curMn, localMin);
		}

		ans += curMn;
	}

	printf("%lld\n", ans);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc)
	{
		printf("Case #%d: ", tc);
		solve();
	}

	return 0;
}
