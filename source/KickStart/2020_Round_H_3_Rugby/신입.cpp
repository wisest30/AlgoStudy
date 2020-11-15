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

struct pt
{
	int x;
	int y;
};

bool operator<(const pt& a, const pt& b)
{
	return a.x < b.x;
}

int N;
pt input[1'00000 + 5];

ll getCost(ll xTarget, ll yTarget)
{
	ll ret = 0;

	for (int i = 0; i < N; i++)
	{
		ret += ABS(xTarget - (input[i].x - i));
		ret += ABS(yTarget - input[i].y);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc)
	{
		scanf("%d", &N);

		for (int i = 0; i < N; i++) scanf("%d %d", &input[i].x, &input[i].y);
		sort(input, input + N);

		vector<ll> yVec;
		vector<ll> xVec;

		for (int i = 0; i < N; i++)
		{
			yVec.push_back(input[i].y);
			xVec.push_back(input[i].x - i);
		}

		sort(yVec.begin(), yVec.end());
		sort(xVec.begin(), xVec.end());

		printf("Case #%d: %lld\n", tc, getCost(xVec[xVec.size() / 2], yVec[yVec.size() / 2]));
	}

	return 0;
}
