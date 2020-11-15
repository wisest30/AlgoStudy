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

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? (-(a)) : (a))

typedef long long ll;

using namespace std;

ll mul[20] = { 1, };

ll getBoring(char *str)
{
	int len = strlen(str);
	ll ret = 0;

	for (int i = 1; i < len; i++) ret += mul[i];

	for (int i = 0; str[i]; i++)
	{
		int j;

		for (j = (i + 1) % 2; j < str[i]-'0'; j += 2)
		{
			ret += mul[len - i - 1];
		}
		if (j > str[i] - '0') break;
		else if (i == len - 1 && j == str[i] - '0') ret++;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	scanf("%d", &T);

	for (int i = 1; i < 20; i++) mul[i] = mul[i - 1] * 5LL;
	
	for (int tc = 1; tc <= T; ++tc)
	{
		char L[20], R[20];
		scanf("%s %s", L, R);

		ll ans = getBoring(R) - getBoring(L);

		bool add = true;

		for (int i = 0; L[i]; i++)
		{
			if (L[i] % 2 != (i + 1) % 2)
			{
				add = false;
				break;
			}
		}

		if (add) ans++;

		printf("Case #%d: %lld\n", tc, ans);
	}

	return 0;
}
