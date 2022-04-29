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
#include <unordered_map>
#include <unordered_set>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? (-(a)) : (a))

typedef long long ll;

using namespace std;

int N, P;
vector<int> inflates[1000+5];

ll memo[1000 + 5][100 + 5];

ll getMemo(int n, int p)
{
	if (memo[n][p] != -1) return memo[n][p];

	if (n == 0)
	{
		int mn = inflates[n][0];
		int mx = inflates[n][P - 1];

		if (p == 0) mn = inflates[n][1];
		if (p == P - 1) mx = inflates[n][P - 2];

		return memo[n][p] = min(
			0LL + mn + (mx - mn) + ABS(mx - inflates[n][p]),
			0LL + mx + (mx - mn) + ABS(mn - inflates[n][p])
		);
	}
	else
	{
		int mn = inflates[n][0];
		int mx = inflates[n][P - 1];

		if (p == 0) mn = inflates[n][1];
		if (p == P - 1) mx = inflates[n][P - 2];

		ll ans = 9e18;

		for (int i = 0; i < P; i++)
		{
			ans = min({
				ans,
				getMemo(n - 1, i) + ABS(inflates[n - 1][i] - mn) + (mx - mn) + ABS(mx - inflates[n][p]),
				getMemo(n - 1, i) + ABS(inflates[n - 1][i] - mx) + (mx - mn) + ABS(mn - inflates[n][p]) 
				});
		}

		return memo[n][p] = ans;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		cout << "Case #" << tc << ": ";
		
		memset(memo, -1, sizeof(memo));
		cin >> N >> P;

		for (int i = 0; i < N; i++)
		{
			inflates[i].clear();
			for (int j = 0; j < P; j++)
			{
				int temp;

				cin >> temp;

				inflates[i].push_back(temp);
			}
			sort(inflates[i].begin(), inflates[i].end());
		}

		ll ans = 9e18;

		for (int i = 0; i < P; i++)
		{
			ll res = getMemo(N - 1, i);
			ans = min(ans, res);
		}

		cout << ans << "\n";
	}

	return 0;
}
