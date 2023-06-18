#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

using namespace std;

typedef long long ll;

int N;
char st[2'00000 + 5];
char ed[2'00000 + 5];

vector<int> stVec;
vector<int> edVec;

void mkVec(char* arr, vector<int>& vec)
{
	char prv = arr[0];
	int len = 1;

	for (int i = 1; arr[i]; i++)
	{
		if (arr[i] == prv) len++;
		else
		{
			vec.push_back(len);
			len = 1;
		}
		prv = arr[i];
	}
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);
		scanf("%s", st);
		scanf("%s", ed);

		st[N] = ed[N] = '#';
		st[N + 1] = ed[N + 1] = 0;

		if (st[0] != ed[0] || st[N - 1] != ed[N - 1])
		{
			printf("-1\n");
			continue;
		}

		stVec.clear();
		edVec.clear();

		mkVec(st, stVec);
		mkVec(ed, edVec);

		if (stVec.size() != edVec.size())
		{
			printf("-1\n");
			continue;
		}

		ll ans = 0;

		for (int i = 0; i < (int)stVec.size() - 1; i++)
		{
			if (stVec[i] > edVec[i])
			{
				int temp = stVec[i] - edVec[i];
				ans += temp;
				stVec[i + 1] += temp;
			}
			else if (stVec[i] < edVec[i])
			{
				int temp = edVec[i] - stVec[i];
				ans += temp;
				stVec[i + 1] -= temp;
			}
		}

		if (stVec.back() != edVec.back()) ans = -1;
		printf("%lld\n", ans);
	}

	return 0;
}
