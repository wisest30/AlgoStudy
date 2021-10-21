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

ll N, D, C, M;
char input[1'0000 + 5];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc)
	{
		printf("Case #%d: ", tc);
		scanf("%lld %lld %lld %lld", &N, &D, &C, &M);
		scanf("%s", input);
		
		int dogCnt = 0;

		for (int i = 0; input[i]; i++)
		{
			if (input[i] == 'D') dogCnt++;
		}

		for (int i = 0; input[i]; i++)
		{
			if (input[i] == 'D')
			{
				if (D == 0) break;
				D--, C += M, dogCnt--;
			}
			else
			{
				if (C == 0) break;
				C--;
			}
		}

		if (dogCnt == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
