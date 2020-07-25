#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? (-(a)) : (a))
 
typedef long long ll;
 
using namespace std;
 
ll cache[151][10];
int digitSum[1000010 + 5];
 
int calcDigitSum(int num)
{
	int res = 0;
 
	while (num)
	{
		res += num % 10;
		num /= 10;
	}
 
	return res;
}
 
ll makeForKZero(int target)
{
	ll res = 0;
	vector<int> output;
	
	while (target >= 9)
	{
		output.push_back(9);
		target -= 9;
	}
	if (target) output.push_back(target);
	reverse(output.begin(), output.end());
	
	for (int digit : output) res = res * 10LL + digit;
	
	return res;
}
 
ll getForKOne(int target)
{
	if (cache[target][1] != -1) return cache[target][1];
	if (target == 0) return cache[target][1] = -2;
 
	ll ans = LONG_MAX;
 
	for (int lastDigit = 0; lastDigit <= 8; lastDigit++)
	{
		int newTargetN = target - lastDigit - (lastDigit + 1);
		if (newTargetN < 0 || newTargetN % 2) continue;
 
		ll newAns = makeForKZero(newTargetN / 2) * 10 + lastDigit;
		if (newAns < ans) ans = newAns;
	}
 
	int newTargetN = target - 9 - 0;
	if (newTargetN >= 0 && getForKOne(newTargetN) != -2)
	{
		ll newAns = getForKOne(newTargetN) * 10 + 9;
		if (newAns < ans) ans = newAns;
	}
 
	if (ans == LONG_MAX) ans = -2;
 
	return cache[target][1] = ans;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(cache, -1, sizeof(cache));
 
	for (int i = 0; i <= 1000010; i++) digitSum[i] = calcDigitSum(i);
	for (int i = 0; i <= 1000000; i++)
	{
		int cumSum = 0;
 
		for (int j = 0; j <= 9; j++)
		{
			cumSum += digitSum[i + j];
			if (cache[cumSum][j] == -1) cache[cumSum][j] = i;
		}
	}
 
	int t;
 
	scanf("%d", &t);
 
	while (t--)
	{
		int n, k;
 
		scanf("%d %d", &n, &k);
		if (k >= 2) printf("%lld\n", cache[n][k]);
		else if (k == 0) printf("%lld\n", makeForKZero(n));
		else
		{
			ll ans = getForKOne(n);
			if (ans == -2) ans = -1;
			printf("%lld\n", ans);
		}
	}
 
	return 0;
}
