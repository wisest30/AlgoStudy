#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <algorithm>
#include <map>
 
using namespace std;
 
const long long mainMod = 1'000'000'007LL;
const long long hashMod = 998'244'353LL;
const long long hashMod2 = 963'247'969LL;
 
int n, p;
int input[1'000'000 + 5];
 
long long getPow(int pow, long long mod)
{
	long long ret = 1LL;
	long long mul = (long long)p;
 
	while (pow)
	{
		if (pow & 1) ret = (ret * mul) % mod;
		mul = (mul * mul) % mod;
		pow >>= 1;
	}
 
	return ret;
}
 
int main()
{
	int t;
 
	scanf("%d", &t);
 
	while (t--)
	{
		scanf("%d %d", &n, &p);
		for (int i = 0; i < n; i++) scanf("%d", &input[i]);
		sort(input, input + n, [&](const int& a, const int& b) { return a > b; });
 
		long long ans = 0LL;
		long long hash = 0LL;
		long long hash2 = 0LL;
 
		for (int i = 0; i < n; i++)
		{
			if (ans == 0 && hash == 0 && hash2 == 0)
			{
				ans = getPow(input[i], mainMod);
				hash = getPow(input[i], hashMod);
				hash2 = getPow(input[i], hashMod2);
			}
			else
			{
				ans = (ans - getPow(input[i], mainMod) + mainMod) % mainMod;
				hash = (hash - getPow(input[i], hashMod) + hashMod) % hashMod;
				hash2 = (hash2 - getPow(input[i], hashMod2) + hashMod2) % hashMod2;
			}
		}
 
		printf("%lld\n", ans);
	}
 
	return 0;
}
