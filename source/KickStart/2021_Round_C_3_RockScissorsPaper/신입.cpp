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
typedef long double ld;

using namespace std;

struct track
{
	ld expected;
	ll lastR;
	ll lastS;
	ll lastP;
};

// R, S, P
track dp[60 + 5][60 + 5][60 + 5];

int X;
int W, E;

ld confirm(string& ans)
{
	ll rCnt = 1;
	ll sCnt = 0;
	ll pCnt = 0;

	ld ret = (ld)W / 3 + (ld)E / 3;

	for (int i = 1; i < ans.size(); i++)
	{
		ll total = rCnt + sCnt + pCnt;

		if (ans[i] == 'R')
		{
			ret += (ld)W * sCnt / total + (ld)E * rCnt / total;
			rCnt++;
		}
		else if (ans[i] == 'S')
		{
			ret += (ld)W * pCnt / total + (ld)E * sCnt / total;
			sCnt++;
		}
		else
		{
			ret += (ld)W * rCnt / total + (ld)E * pCnt / total;
			pCnt++;
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	cin >> T;
	cin >> X;

	for (int tc = 1; tc <= T; ++tc)
	{
		cin >> W >> E;
		memset(dp, 0, sizeof(dp));
		dp[1][0][0].expected = (ld)W / 3 + (ld)E / 3;

		ld mxExpected = 0;
		ll ansR, ansP, ansS;

		for (ll i = 2; i <= 60; i++)
		{
			for (ll j = 0; j <= i - 1; j++)
			{
				for (ll k = 0; k <= (i - 1) - j; k++)
				{
					if (dp[j][k][i - 1 - j - k].expected == 0) continue;

					ld rProb = (ld)k / (i - 1LL);
					ld pProb = (ld)j / (i - 1LL);
					ld sProb = (ld)(i - 1 - j - k) / (i - 1LL);

					ld rExpected = dp[j][k][i - 1 - j - k].expected + (ld)W * sProb + (ld)E * rProb;
					ld sExpected = dp[j][k][i - 1 - j - k].expected + (ld)W * pProb + (ld)E * sProb;
					ld pExpected = dp[j][k][i - 1 - j - k].expected + (ld)W * rProb + (ld)E * pProb;

					track& rAdded = dp[j + 1][k][i - 1 - j - k];
					track& sAdded = dp[j][k + 1][i - 1 - j - k];
					track& pAdded = dp[j][k][i - j - k];

					if (rAdded.expected < rExpected)
					{
						rAdded.expected = rExpected;
						rAdded.lastR = j;
						rAdded.lastS = k;
						rAdded.lastP = i - 1 - j - k;
					}
					if (sAdded.expected < sExpected)
					{
						sAdded.expected = sExpected;
						sAdded.lastR = j;
						sAdded.lastS = k;
						sAdded.lastP = i - 1 - j - k;
					}
					if (pAdded.expected < pExpected)
					{
						pAdded.expected = pExpected;
						pAdded.lastR = j;
						pAdded.lastS = k;
						pAdded.lastP = i - 1 - j - k;
					}

					if (i == 60)
					{
						if (rAdded.expected > mxExpected)
						{
							mxExpected = rAdded.expected;
							ansR = j + 1;
							ansS = k;
							ansP = i - 1 - j - k;
						}
						if (sAdded.expected > mxExpected)
						{
							mxExpected = sAdded.expected;
							ansR = j;
							ansS = k + 1;
							ansP = i - 1 - j - k;
						}
						if (pAdded.expected > mxExpected)
						{
							mxExpected = pAdded.expected;
							ansR = j;
							ansS = k;
							ansP = i - j - k;
						}
					}
				}
			}
		}

		string ans = "";

		for (; ansR || ansS || ansP;)
		{
			ll lastR = dp[ansR][ansS][ansP].lastR;
			ll lastS = dp[ansR][ansS][ansP].lastS;
			ll lastP = dp[ansR][ansS][ansP].lastP;

			if (lastR == ansR - 1) ans += "R";
			else if (lastS == ansS - 1) ans += "S";
			else ans += "P";

			ansR = lastR;
			ansS = lastS;
			ansP = lastP;
		}

		reverse(ans.begin(), ans.end());
		confirm(ans);

		cout << "Case #" << tc << ": " << ans << "\n";
	}

	return 0;
}
