#include <stdio.h>
 
typedef long long ll;
 
constexpr int MAXN = 3000;
int rightCnt[MAXN + 5][MAXN + 5];
int leftCnt[MAXN + 5];
int input[MAXN + 5];
int n;
 
int main()
{
	ll ans;
	int t;
 
	scanf("%d", &t);
 
	while (t--)
	{
		ans = 0;
		scanf("%d", &n);
 
		for (int i = 0; i < n; i++) scanf("%d", &input[i]);
		input[n] = 0;
 
		for (int i = 1; i <= n; i++) rightCnt[n][i] = 0;
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = 1; j <= n; j++) rightCnt[i][j] = rightCnt[i + 1][j];
			rightCnt[i][input[i]]++;
		}
 
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j <= n; j++) leftCnt[j] = 0;
			int curCnt = 0;
 
			for (int j = i + 1; j < n; j++)
			{
				if(input[j] == input[i]) ans += curCnt;
				curCnt -= leftCnt[input[j]] * rightCnt[j + 1][input[j]];
				if(input[j+1] != input[j]) curCnt -= leftCnt[input[j + 1]] * rightCnt[j + 1][input[j + 1]];
				leftCnt[input[j]]++;
				curCnt += leftCnt[input[j]] * rightCnt[j + 2][input[j]];
				if(input[j+1] != input[j]) curCnt += leftCnt[input[j + 1]] * rightCnt[j + 2][input[j + 1]];
			}
		}
 
		printf("%lld\n", ans);
	}
 
	return 0;
}
