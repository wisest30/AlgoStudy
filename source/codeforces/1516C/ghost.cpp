#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <memory.h>

using namespace std;
typedef long long ll;
int N;

vector<int> a(100);
vector<int> cp(100);
int memo[101][200000];

int gcd(int a, int b) {
	int n;
	while (b) {
		n = a%b;
		a = b;
		b = n;
	}
	return a;
}

bool pos(int d, int pSum, int sum)
{
	int& ret = memo[d][pSum];
	if (~ret)	return ret;
	if (pSum == sum) return ret = true;
	if (pSum > sum || d == N)	return ret = false;
	return ret = pos(d + 1, pSum, sum) || pos(d + 1, pSum + a[d], sum);
}

int main()
{
	memset(memo, -1, sizeof(int) * 101 * 200000);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	int sum = accumulate(a.begin(), a.begin() + N, 0);
	copy(a.begin(), a.begin() + N, cp.begin());
	sort(a.begin(), a.begin() + N, greater<int>());
	if (sum & 1 || !pos(1, a[0], sum/2))
		printf("0\n");
	else
	{
		int g = a[N-1];
		for (int i = N - 2; ~i; i--)	g = gcd(a[i], g);
		for (int i = 0; i < N; i++)
		{
			if ((cp[i] / g) & 1)
			{
				printf("1 %d\n", i + 1);
				break;
			}
		}			
	}
	return 0;
}

