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

vector<int> xs;
vector<int> ys;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc)
	{
		printf("Case #%d: ", tc);
		
		int N;
		
		xs.clear();
		ys.clear();

		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			xs.push_back(x1);
			xs.push_back(x2);
			ys.push_back(y1);
			ys.push_back(y2);
		}

		sort(xs.begin(), xs.end());
		sort(ys.begin(), ys.end());

		printf("%d %d\n", xs[(xs.size() - 1) / 2], ys[(ys.size() - 1) / 2]);
	}
	return 0;
}
