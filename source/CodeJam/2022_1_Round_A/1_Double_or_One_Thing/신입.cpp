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
#include <math.h>
#include <unordered_map>
#include <unordered_set>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? (-(a)) : (a))

typedef long long ll;

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		string input;
		string output;

		cin >> input;

		for (int i = 0; i < input.size(); i++)
		{
			bool twice = false;

			for (int j = i + 1; j < input.size(); j++)
			{
				if (input[i] != input[j])
				{
					if (input[i] < input[j]) twice = true;
					else twice = false;
					break;
				}
			}

			output += input[i];
			if (twice) output += input[i];
		}

		cout << "Case #" << tc << ": " << output << "\n";
	}

	return 0;
}
