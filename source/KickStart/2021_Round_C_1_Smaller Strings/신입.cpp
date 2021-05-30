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

ll N, K;
const ll mod = 1e9 + 7;

string input;

ll convert(const string& str)
{
	ll ret = 0;
	for (int i = 0; i < str.size(); i++)
	{
		ret = ret * K + str[i] - 'a';
		ret %= mod;
	}
	return (ret + 1) % mod;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		cin >> N >> K;
		cin >> input;

		string left = "";
		string right = "";

		for (int i = 0; i < N / 2; i++) left += input[i];
		right = left;
		reverse(right.begin(), right.end());

		ll ans;

		if (N % 2 == 0)
		{
			string total = left + right;
			ans = (convert(left) - 1 + mod) % mod;
			if (total < input) ans = (ans + 1) % mod;
		}
		else
		{
			string total = left + input[N / 2] + right;
			ans = (((convert(left) - 1 + mod) % mod) * K) % mod + (input[N / 2] - 'a');
			if (total < input) ans = (ans + 1) % mod;
		}

		cout << "Case #" << tc << ": " << ans << "\n";
	}

	return 0;
}
