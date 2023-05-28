#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

char guess[1'000 + 5];
int rightBorder[26 + 5];
int firstAppear[26 + 5];
int leftBorder[26 + 5];

int main()
{
	memset(firstAppear, 0x3f, sizeof(firstAppear));
	int n;

	scanf("%d", &n);

	printf("? 2 1 %d\n", n);
	fflush(stdout);

	int totalCnt;

	scanf("%d", &totalCnt);

	int temp = totalCnt;
	rightBorder[temp] = n;

	while (temp > 1)
	{
		int curCnt;
		int hi = rightBorder[temp];
		int lo = 1;

		while (lo <= hi)
		{
			int mid = lo + (hi - lo) / 2;

			printf("? 2 1 %d\n", mid);
			fflush(stdout);

			scanf("%d", &curCnt);

			if (curCnt <= temp - 1)
			{
				rightBorder[temp - 1] = mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}

		temp--;
	}

	for (int i = 0; i < totalCnt; i++)
	{
		printf("? 1 %d\n", rightBorder[i] + 1);
		fflush(stdout);

		scanf(" %c", &guess[rightBorder[i] + 1]);
		firstAppear[guess[rightBorder[i] + 1] - 'a'] = rightBorder[i] + 1;
	}

	int alphabetCur = 0;
	vector<char> validAlphabets;
	bool inValid[26]{};

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (i > firstAppear[j] && !inValid[j])
			{
				validAlphabets.push_back(j + 'a');
				leftBorder[j] = firstAppear[j];
				inValid[j] = true;
				break;
			}
		}

		if (guess[i]) continue;

		vector<int> leftBorders;

		for (char ch : validAlphabets) leftBorders.push_back(leftBorder[ch - 'a']);
		sort(leftBorders.begin(), leftBorders.end());

		int lo = 0;
		int hi = (int)leftBorders.size() - 1;

		while (lo <= hi)
		{
			int mid = lo + (hi - lo) / 2;

			printf("? 2 %d %d\n", leftBorders[mid], i);
			fflush(stdout);

			int localCnt;

			scanf("%d", &localCnt);

			if (localCnt == (int)leftBorders.size() - mid)
			{
				guess[i] = guess[leftBorders[mid]];
				lo = mid + 1;
			}
			else hi = mid - 1;
		}

		leftBorder[guess[i] - 'a'] = i;
	}

	printf("! %s\n", guess + 1);
	fflush(stdout);


	return 0;
}
