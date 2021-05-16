#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

int solve2(int N) {
	if (N < 2)	return 0;
	int& ret = dp[N];
	if (ret) return ret;
	ret = 1;
	for (int i = 2; i * i <= N; i++)
		if (N % i == 0)
		{
			ret = max(ret, 1 + solve2(N / i - 1));
			ret = max(ret, 1 + solve2(i - 1));
		}
	return ret;
}

int solve1(int N)
{
	int ret = 1;
	for (int i = 3; i * i <= N; i++)
		if (N % i == 0)
		{
			ret = max(ret, 1 + solve2(N / i - 1));
			ret = max(ret, 1 + solve2(i - 1));
		}
			
	return ret;
}

int main()
{
	int T=0, N;
	scanf("%d", &T);
	for(int tc= 1 ;tc <= T; tc++)
	{
		scanf("%d", &N);
		printf("Case #%d: %d\n", tc, solve1(N));
	}
	return 0;
}

