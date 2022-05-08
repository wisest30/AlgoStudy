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

int N, K;

void solve()
{
	cin >> N >> K;

	ll sqSum = 0;
	ll sum = 0;

	for (int i = 0; i < N; i++)
	{
		int temp;

		cin >> temp;
		sqSum += 1LL * temp * temp;
		sum += temp;
	}

	ll sumSquare = sum * sum;

	if (K > 1)
	{
		if((sqSum+sumSquare)%2) cout << "IMPOSSIBLE\n";
		else if (sqSum + sumSquare == 0) cout << -sum << " " << -sum << "\n";
		else
		{
			cout << 1 - sum << " " << (sqSum + sumSquare) / 2 - sum << "\n";
		}
		return;
	}

	if (sum == 0)
	{
		if (sqSum - sumSquare == 0) cout << "0\n";
		else cout << "IMPOSSIBLE\n";
	}
	else
	{
		if ((sqSum - sumSquare) % (2 * sum) == 0) cout << (sqSum - sumSquare) / (2 * sum) << "\n";
		else cout << "IMPOSSIBLE\n";
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
		solve();
	}
	return 0;
}
