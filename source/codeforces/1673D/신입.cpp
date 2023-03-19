#include <stdio.h>

typedef long long ll;
constexpr ll MOD = 1e9 + 7;

ll b, q, y;
ll c, r, z;

ll lastC;
ll posOfLastCinB ;
ll posOfFirstCinB;

bool infiniteAns;

ll getGCD(ll a, ll b)
{
	if (a%b == 0) return b;
	return getGCD(b, a%b);
}

ll getLCM(ll a, ll b)
{
	ll gcd = getGCD(a, b);
	return a / gcd * b / gcd * gcd;
}

ll getCnt(ll diff)
{
	ll lcm = getLCM(diff, q);

	if (lcm < r) return 0LL;

	ll leftRange = posOfFirstCinB - lcm / q;
	ll rightRange = posOfLastCinB + lcm / q;

	if (leftRange < 1 || rightRange > y) {
		infiniteAns = true;
		return 0LL;
	}

	return ((lcm / diff) * (lcm / diff)) % MOD;
}

int main()
{
	int t;

	scanf("%d", &t);

	while (t--)
	{
		scanf("%lld %lld %lld", &b, &q, &y);
		scanf("%lld %lld %lld", &c, &r, &z);

		lastC = c + r * (z - 1);
		posOfLastCinB = 0;
		posOfFirstCinB = 0;

		infiniteAns = false;
		
		if (r % q == 0 && (lastC - b) % q == 0) posOfLastCinB = (lastC - b) / q + 1;

		if ((c - b) % q == 0) posOfFirstCinB = (c - b) / q + 1;

		if (posOfLastCinB < 1 || posOfLastCinB > y || posOfFirstCinB < 1 || posOfFirstCinB > y) 
		{
			printf("0\n");
			continue;
		}

		ll ans = 0;

		for (ll i = 1; i*i <= r && !infiniteAns; i++)
		{
			if (r%i == 0)
			{
				ans = (ans + getCnt(i)) % MOD;
				if (i != r / i) ans = (ans + getCnt(r / i)) % MOD;
			}
		}

		if (infiniteAns) printf("-1\n");
		else printf("%lld\n", ans);
	}

	return 0;
}
