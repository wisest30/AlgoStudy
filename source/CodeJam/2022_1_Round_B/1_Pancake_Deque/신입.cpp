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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		cout << "Case #" << tc << ": ";
		int N;

		cin >> N;

		deque<int> dq;

		for (int i = 0; i < N; i++)
		{
			int temp;

			cin >> temp;
			dq.push_back(temp);
		}

		int ans = 0;
		int mx = 0;

		while (!dq.empty())
		{
			if (dq.front() < dq.back())
			{
				if (dq.front() >= mx)
				{
					ans++;
					mx = dq.front();
				}
				dq.pop_front();
			}
			else
			{
				if (dq.back() >= mx)
				{
					ans++;
					mx = dq.back();
				}
				dq.pop_back();
			}
		}

		cout << ans << "\n";
	}

	return 0;
}
