#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

int n;
int input[2'00000 + 5];

int main()
{
	multiset<int> mset;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input[i]);
		mset.insert(input[i]);
	}

	int ans = 0;

	ans += (*mset.begin() + 1) / 2;
	mset.erase(mset.begin());

	ans += (*mset.begin() + 1) / 2;

	for (int i = 0; i + 1 < n; i++)
	{
		int small = input[i];
		int big = input[i + 1];
		
		if (small > big) swap(small, big);

		if (small * 2 <= big) ans = min(ans, (big + 1) / 2);
		else
		{
			int tmp = (big - small);
			
			big -= 2 * tmp;
			small -= tmp;

			ans = min(ans, tmp + (big / 3) * 2 + big % 3);
		}
	}

	for (int i = 0; i + 2 < n; i++)
	{
		int small = input[i];
		int big = input[i + 2];

		if (small > big) swap(small, big);

		ans = min(ans, small + (big - small + 1) / 2);
	}

	printf("%d\n", ans);

	return 0;
}
