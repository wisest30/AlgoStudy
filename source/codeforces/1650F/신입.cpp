#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Track
{
	string path;
	int t;
};

struct Input
{
	int e;
	int t;
	int p;
	int idx;
};

bool operator<(const Input &a, const Input &b)
{
	return a.e < b.e;
}

const int INF = 0x3f3f3f3f;

Input input[1'00000 + 5];

int N, M;
Track minTime[1'00 + 5];
int stTime[1'00000 + 5];

vector<int> succeeded;
vector<int> output;

void buildPrint()
{
	int cur = 0;

	for (char ch : minTime[100].path)
	{
		if (ch == '#')
		{
			output.push_back(cur);
			cur = 0;
		}
		else cur = cur * 10 + ch - '0';
	}
}

void initMinTime()
{
	for (int i = 100; i > 0; --i) minTime[i].t = INF;
	minTime[0].t = 0;
	minTime[0].path = "";
}

int main()
{
	int T;

	scanf("%d", &T);

	int originT = T;

	while (T--)
	{
		initMinTime();
		output.clear();
		succeeded.clear();

		scanf("%d %d", &N, &M);

		for (int i = 1; i <= N; i++) scanf("%d", &stTime[i]);

		for (int i = 1; i <= M; i++)
		{
			scanf("%d %d %d", &input[i].e, &input[i].t, &input[i].p);
			input[i].idx = i;
		}

		input[M + 1].e = N + 1;

		sort(input + 1, input + M + 1);

		int curTime = 0;
		bool success = true;

		for (int i = 1; i <= M + 1; i++)
		{
			int e = input[i].e;
			int t = input[i].t;
			int p = input[i].p;

			if (i != 1 && e != input[i - 1].e)
			{
				curTime += minTime[100].t;
				if (curTime > stTime[input[i - 1].e])
				{
					success = false;
					break;
				}
				succeeded.push_back(input[i - 1].e);
				buildPrint();
				initMinTime();
			}

			for (int j = 99; j >= 0; --j)
			{
				int target = j + p;
				if (target > 100) target = 100;

				if (minTime[j].t + t < minTime[target].t)
				{
					minTime[target].t = minTime[j].t + t;
					minTime[target].path = minTime[j].path + to_string(input[i].idx);
					minTime[target].path += "#";
				}
			}
		}

		if (!success) printf("-1\n");
		else
		{
			if (succeeded.size() != N) printf("-1\n");
			else
			{
				printf("%d\n", output.size());
				for (int num : output) printf("%d ", num);
				printf("\n");
			}
		}
	}

	return 0;
}
