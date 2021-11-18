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

int N;
char P[1'00000 + 5];

void solve()
{
	scanf("%d", &N);
	scanf("%s", P);
	P[N] = 'U';
	P[N + 1] = 0;

	int ans = 0;
	int curLen = 0;

	// R
	for (int i = 0; P[i]; i++)
	{
		if (P[i] == 'R' || P[i] == 'O' || P[i] == 'P' || P[i] == 'A') curLen++;
		else
		{
			if (curLen) ans++;
			curLen = 0;
		}
	}

	// Y
	for (int i = 0; P[i]; i++)
	{
		if (P[i] == 'Y' || P[i] == 'O' || P[i] == 'G' || P[i] == 'A') curLen++;
		else
		{
			if (curLen) ans++;
			curLen = 0;
		}
	}

	// B
	for (int i = 0; P[i]; i++)
	{
		if (P[i] == 'B' || P[i] == 'P' || P[i] == 'G' || P[i] == 'A') curLen++;
		else
		{
			if (curLen) ans++;
			curLen = 0;
		}
	}

	printf("%d\n", ans);
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
