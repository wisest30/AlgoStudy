#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <algorithm>
#include <vector>

using namespace std;

vector<int> primes;
int isNotPrime[32500] = { true, true, false, };

int N;
vector<int> divisors;

vector<int> curVec;

int ansLen;
vector<int> ans;

void dfs(int idx, int curVecSum)
{
	if (curVecSum > 41) return;

	if (idx == divisors.size())
	{
		if (curVec.size() + (41 - curVecSum) < ansLen)
		{
			ansLen = curVec.size() +(41 - curVecSum);
			ans = curVec;
		}

		return;
	}

	for (int i = 0; i < curVec.size(); i++)
	{
		if (i && curVec[i] == curVec[i - 1]) continue;

		int oldCurVec = curVec[i];
		curVec[i] *= divisors[idx];
		dfs(idx + 1, curVecSum + curVec[i] - oldCurVec);
		curVec[i] /= divisors[idx];
	}

	curVec.push_back(divisors[idx]);
	dfs(idx + 1, curVecSum + divisors[idx]);
	curVec.pop_back();
}

void solve()
{
	divisors.clear();

	ansLen = 50;
	scanf("%d", &N);

	int primesCur = 0;

	while (primesCur < primes.size() && N >= primes[primesCur])
	{
		while (N % primes[primesCur] == 0)
		{
			N /= primes[primesCur];
			divisors.push_back(primes[primesCur]);
		}

		primesCur++;
	}

	if (N != 1) divisors.push_back(N);

	dfs(0, 0);

	if (ansLen == 50) printf("-1\n");
	else
	{
		printf("%d ", ansLen);
		for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
		for (int i = 0; i < ansLen - ans.size(); i++) printf("1 ");
		printf("\n");
	}
}

void init()
{
	for (int i = 2; 1LL * i * i <= 1'000'000'000LL; i++)
	{
		if (!isNotPrime[i]) primes.push_back(i);

		for (int j = i * i; 1LL * j * j <= 1'000'000'000LL; j += i) isNotPrime[j] = true;
	}
}

int main()
{
	init();

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
