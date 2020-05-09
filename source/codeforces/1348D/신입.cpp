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
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
 
	scanf("%d", &t);
 
	while (t--)
	{
		ll n;
 
		ll diff = 1LL;
		ll size = 1LL;
 
		vector<ll> ans;
 
		scanf("%lld", &n);
 
		while (size < n)
		{
			if (size + 2 * diff >= n)
			{
				ans.push_back((n - size) - diff);
				diff = n - size;
			}
			else if (size + 4 * diff < n)
			{
				ans.push_back(diff);
				diff = 2 * diff;
			}
			else
			{
				ans.push_back((n - size) / 2 - diff);
				diff = (n - size) / 2;
			}
			size += diff;
		}
 
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < ans.size(); ++i) printf("%lld ", ans[i]);
		printf("\n");
	}
 
	return 0;
}
