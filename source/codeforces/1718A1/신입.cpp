#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include <algorithm>

using namespace std;

int N;
int input[5'000 + 5];

int memo[2][8192 + 5]{};

int solve()
{
	memset(memo, 0x7f, sizeof(memo));

	scanf("%d", &N);

	for (int i = 0; i < N; i++) scanf("%d", &input[i]);

	memo[0][0] = 1;
	memo[0][input[0]] = 0;

	for (int i = 1; i < N; i++)
	{
		// select length 0
		memo[i & 1][input[i]] = memo[(i + 1) & 1][0];

		// select length 1
		memo[i & 1][0] = memo[(i + 1) & 1][0];
		if (input[i]) memo[i & 1][0]++;
		
		// select length 2
		for (int j = 1; j < 8192; j++)
		{
			int& cur = memo[i & 1][input[i] ^ j];
			const int& prv = memo[(i + 1) & 1][j];

			cur = min(cur, prv + 1);
		}

		memset(memo[(i + 1) & 1], 0x7f, sizeof(memo[(i + 1) & 1]));
	}
	
	return memo[(N - 1) & 1][0];
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--) printf("%d\n", solve());
	
	return 0;
}
