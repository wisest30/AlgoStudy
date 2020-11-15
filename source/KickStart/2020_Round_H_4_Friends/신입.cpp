#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

const int INT_MAX = 2147483647;

int N;
char input[5'0000 + 5][20 + 5];

int alphabetDist[26][26];

void init()
{
	for (int i = 0; i < 26; i++)
	{
		alphabetDist[i][i] = 0;
		for (int j = i + 1; j < 26; j++)
		{
			alphabetDist[i][j] = alphabetDist[j][i] = INT_MAX;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc)
	{
		init();

		int Q;
		scanf("%d %d", &N, &Q);
		
		for (int i = 0; i < N; i++)
		{
			scanf("%s", input[i]);
			for (int j = 0; input[i][j]; j++)
			{
				for (int k = j + 1; input[i][k]; k++)
				{
					int firstPos = input[i][j] - 'A';
					int secondPos = input[i][k] - 'A';

					alphabetDist[firstPos][secondPos] = min(alphabetDist[firstPos][secondPos], 1);
					alphabetDist[secondPos][firstPos] = alphabetDist[firstPos][secondPos];
				}
			}
		}

		for (int k = 0; k < 26; k++)
		{
			for (int i = 0; i < 26; i++)
			{
				if (alphabetDist[i][k] == INT_MAX) continue;

				for (int j = i + 1; j < 26; j++)
				{
					if (alphabetDist[k][j] == INT_MAX) continue;

					alphabetDist[i][j] = min(alphabetDist[i][j], alphabetDist[i][k] + alphabetDist[k][j]);
					alphabetDist[j][i] = alphabetDist[i][j];
				}
			}
		}

		printf("Case #%d:", tc);
		for (int i = 0; i < Q; i++)
		{
			int w1, w2;

			scanf("%d %d", &w1, &w2);
			w1--, w2--;

			int dist = INT_MAX;

			for (int j = 0; input[w1][j]; j++)
			{
				for (int k = 0; input[w2][k]; k++)
				{
					dist = min(dist, alphabetDist[input[w1][j]-'A'][input[w2][k]-'A']);
				}
			}

			if (dist == INT_MAX) printf(" -1");
			else printf(" %d", dist + 2);
		}
		printf("\n");
	}

	return 0;
}
