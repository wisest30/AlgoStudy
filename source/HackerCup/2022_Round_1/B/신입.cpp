#include <stdio.h>

typedef long long ll;

using namespace std;

const ll MOD = 1e9 + 7;

void solve()
{
	int N, Q;

	ll squareSumA = 0, squareSumB = 0;
	ll sumA = 0, sumB = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		ll A, B;

		scanf("%lld %lld", &A, &B);

		sumA = (sumA + A) % MOD;
		sumB = (sumB + B) % MOD;

		squareSumA = (squareSumA + (A*A) % MOD) % MOD;
		squareSumB = (squareSumB + (B*B) % MOD) % MOD;
	}

	scanf("%d", &Q);
	ll ans = 0;

	for (int i = 0; i < Q; i++)
	{
		ll X, Y;

		scanf("%lld %lld", &X, &Y);

		ans = (ans + squareSumA + squareSumB) % MOD;

		ll tempResX = (N*X) % MOD;
		ll tempResY = (N*Y) % MOD;

		ans = (ans + (MOD - (2 * sumA*X) % MOD) + (MOD - (2 * sumB*Y) % MOD)) % MOD;
		ans = (ans + ((tempResX*X) % MOD) + ((tempResY*Y) % MOD)) % MOD;
	}
	
	printf("%lld\n", ans);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc)
	{
		printf("Case #%d: ", tc);
		solve();
	}

	return 0;
}
