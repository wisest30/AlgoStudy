#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

using namespace std;

constexpr int MAX = 1'644'934'081;
constexpr int SQRT_MAX = 40557;

struct Element
{
	int val;
	int sign;
};

vector<int> primes;
vector<Element> candidates;
bool isNotPrime[SQRT_MAX + 5];
int primeDivisorCnt[SQRT_MAX + 5];
int calc[SQRT_MAX + 5];

void init()
{
	for (int i = 2; i <= SQRT_MAX; i++)
	{
		calc[i] = i;
		if (!isNotPrime[i])
		{
			primes.push_back(i);
			for (int j = i * i; j <= SQRT_MAX; j += i) isNotPrime[j] = true;
		}
	}

	for (const auto& prime : primes)
	{
		for (int j = 1; prime * j <= SQRT_MAX; j++)
		{
			calc[prime * j] /= prime;
			primeDivisorCnt[prime * j]++;
		}
	}

	for (int i = 2; i <= SQRT_MAX; i++)
	{
		if (calc[i] == 1)
		{
			if (primeDivisorCnt[i] % 2) candidates.push_back({ i * i, -1 });
			else candidates.push_back({ i * i, 1 });
		}
	}
}

int getCnt(int target)
{
	int ret = target;

	for (int i = 0; i < (int)candidates.size() && target >= candidates[i].val; i++) ret += target / candidates[i].val * candidates[i].sign;
	return ret;
}

int main()
{
	init();

	int K;

	scanf("%d", &K);

	int lo = 1;
	int hi = MAX;

	while (lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;

		int cnt = getCnt(mid);

		if (cnt >= K) hi = mid - 1;
		else lo = mid + 1;
	}

	printf("%d\n", hi + 1);
	return 0;
}
