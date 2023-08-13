#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

struct Element
{
	ll val;
	int used;
};

bool operator<(const Element& a, const Element& b)
{
	if (a.val != b.val) return a.val < b.val;
	return a.used < b.used;
}

ll fibo[60] = { 1, 1, 2, };
vector<ll> fiboSum = { 1, 2, 4 };

int main()
{
	for (int i = 3;; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fiboSum.push_back(fiboSum.back() + fibo[i]);

		if (fiboSum.back() > 1'000'000'000'00LL) break;
	}

	int T;

	scanf("%d", &T);

	while (T--)
	{
		int k;

		scanf("%d", &k);

		ll sum = 0;
		priority_queue<Element> pq;

		for (int i = 0; i < k; i++)
		{
			ll temp;

			scanf("%lld", &temp);
			pq.push({ temp, 60 });

			sum += temp;
		}

		auto it = lower_bound(fiboSum.begin(), fiboSum.end(), sum);
		int idx = it - fiboSum.begin();

		if (fiboSum[idx] != sum)
		{
			printf("NO\n");
			continue;
		}
		else
		{
			bool valid = true;

			for (int i = idx; i >= 0; --i)
			{
				Element cur = pq.top();
				pq.pop();

				if (cur.used == i + 1)
				{
					valid = false;
					break;
				}

				if (cur.val - fibo[i] > 0)
				{
					Element nxt{ cur.val - fibo[i], i };
					pq.push(nxt);
				}
				else if (cur.val - fibo[i] < 0)
				{
					valid = false;
					break;
				}
			}

			if (valid) printf("YES\n");
			else printf("NO\n");
		}
	}

	return 0;
}
