#include <stdio.h>
#include <deque>

using namespace std;

typedef long long ll;

constexpr size_t MAXN = 2'000'000;
constexpr ll MOD = 1'000'000'007;

ll binary[2 * MAXN + 5] = { 1, };
ll invBinary;

int N;
int input[2 * MAXN + 5];

ll getPow(ll base, ll pow)
{
	ll ret = 1;

	while (pow)
	{
		if (pow & 1) ret = (ret * base) % MOD;
		base = (base * base) % MOD;
		pow /= 2;
	}

	return ret;
}

void init()
{
	for (int i = 1; i < 2 * MAXN; i++) binary[i] = (binary[i - 1] * 2LL) % MOD;
	invBinary = getPow(2LL, MOD - 2);
}

void solve()
{
	ll originHash = 0LL;
	ll reversedHash = 0LL;

	deque<int> dq, diffDq;
	int firstHalfMinus = 0;
	int secondHalfPlus = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input[i]);
		dq.push_back(input[i]);
		originHash = (originHash * 2LL) % MOD;
		originHash = (originHash + input[i]) % MOD;
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input[N + i]);
		dq.push_back(input[N + i]);
		originHash = (originHash * 2LL) % MOD;
		originHash = (originHash + input[N+i]) % MOD;
	}

	for (int i = 0; i < 2 * N; i++)
	{
		reversedHash = (reversedHash * 2LL) % MOD;
		reversedHash = (reversedHash + input[2 * N - 1 - i]) % MOD;
	}

	for (int i = 0; i < N; i++)
	{
		int val = input[i] - input[N + i];
		
		diffDq.push_back(val);
		
		if (i < N / 2 && val < 0) firstHalfMinus++;
		if (i >= (N + 1) / 2 && val > 0) secondHalfPlus++;
	}
	
	for (int i = 0; i < 2 * N; i++)
	{
		if (originHash == reversedHash && firstHalfMinus == N / 2 && secondHalfPlus == N / 2)
		{
			bool valid = true;

			for (int j = 0; j < N; j++)
			{
				if (dq[j] != dq[2 * N - 1 - j])
				{
					valid = false;
					break;
				}
			}

			if (valid)
			{
				printf("%d\n", i);
				return;
			}
		}

		originHash = (originHash + MOD - (dq.front() * binary[2 * N - 1]) % MOD) % MOD;
		originHash = (originHash * 2LL) % MOD;
		originHash = (originHash + (dq.front() * binary[0]) % MOD) % MOD;

		reversedHash = (reversedHash + MOD - (dq.front() * binary[0]) % MOD) % MOD;
		reversedHash = (reversedHash * invBinary) % MOD;
		reversedHash = (reversedHash + (dq.front() * binary[2 * N - 1]) % MOD) % MOD;

		if (diffDq.front() < 0) firstHalfMinus--;
		if (diffDq[(N + 1) / 2] > 0) secondHalfPlus--;

		diffDq.pop_front();
		diffDq.push_back(dq[N] - dq.front());

		if (diffDq.back() > 0) secondHalfPlus++;
		if (diffDq[N / 2 - 1] < 0) firstHalfMinus++;

		int temp = dq.front();
		dq.pop_front();
		dq.push_back(temp);
	}

	printf("-1\n");
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	init();

	int T;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc)
	{
		printf("Case #%d: ", tc);
		solve();
	}

	return 0;
}
