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
		vector<int> arr;

		int N;
		ll sum = 0;

		cin >> N;

		for (int i = 0; i < 30; i++)
		{
			cout << (1LL << i) << " ";
			sum += (1LL << i);
		}
		for (int i = 30; i < 100; i++)
		{
			sum += 256 + i;
			cout << 256 + i << " ";
			arr.push_back(256 + i);
		}
		cout << endl;

		for (int i = 0; i < 100; i++)
		{
			int temp;
			cin >> temp;
			sum += temp;
			arr.push_back(temp);
		}

		sum /= 2;
		ll temp = 1;

		while (sum >= (1<<30))
		{
			cout << arr.back() << " ";
			sum -= arr.back();
			arr.pop_back();
		}

		while (sum)
		{
			if (sum & 1LL) cout << temp << " ";
			sum /= 2;
			temp *= 2;
		}

		cout << endl;
	}

	return 0;
}
