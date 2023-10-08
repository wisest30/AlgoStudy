#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int input[1'00000 + 5];

void solve()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) scanf("%d", &input[i]);
	sort(input, input + N);

	int ans;

	if (N == 5)
	{
		ans = max(ans, input[N - 1] + input[N - 2] - input[0] - input[2]);
		ans = max(ans, input[N - 1] + input[N - 3] - input[0] - input[1]);
	}
	else ans = input[N - 1] + input[N - 2] - input[0] - input[1];

	printf("%d", ans / 2);

	if (ans % 2) printf(".5");

	printf("\n");
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
