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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		ll G;
		ll ans = 0;

		cin >> G;

		for (ll i = 1; i * i <= 8 * G; i++)
		{
			if ((8 * G) % i == 0)
			{
				ll total = (8 * G) / i + i;
				if (total % 2) continue;

				ll A = total / 2;
				if (A <= 0) continue;
				
				if (((8 * G) / i - A + 1) % 2 == 0)
				{
					ll K = ((8 * G) / i - A + 1) / 2;
					if (K <= 0) continue;

					if ((-(2 * K - 1) + A) > 0 && (-(2 * K - 1) + A) % 2 == 0) ans++;
				}
			}
		}

		cout << "Case #" << tc << ": " << ans << "\n";
	}

	return 0;
}
