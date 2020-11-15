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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	scanf("%d", &T);
	
	for (int tc = 1; tc <= T; ++tc)
	{
		ll N, K, S;
		scanf("%lld %lld %lld", &N, &K, &S);

		printf("Case #%d: %lld\n", tc, min(N + K, K - 1 + K - S + N - S + 1));
	}

	return 0;
}
