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

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? (-(a)) : (a))

typedef long long ll;
typedef long double ld;

using namespace std;

map<pair<ll, ll>, ll> sharpResult;
map<pair<ll, ll>, int> group;
int groupSz;

const ll mod1 = 999999937;
const ll mod2 = 998244353;

string input[100 + 5];

ll getSharpResult(pair<ll, ll> key)
{
	if (sharpResult.find(key) == sharpResult.end()) return sharpResult[key] = rand();
	return sharpResult[key];
}

ll registerStr(string& str)
{
	stack<pair<ll, ll>> numStack;
	stack<char> operStack;

	pair<ll, ll> curNum;
	bool numVisit = false;
	curNum.first = 0;
	curNum.second = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '#' || str[i] == '+' || str[i] == '*')
		{
			if (numVisit)
			{
				numStack.push(curNum);
				curNum.first = 0, curNum.second = 0;
				numVisit = false;
			}
			operStack.push(str[i]);
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			numVisit = true;
			curNum.first = ((curNum.first) * 10LL + str[i] - '0') % mod1;
			curNum.second = ((curNum.second) * 10LL + str[i] - '0') % mod2;
		}
		else if(str[i] == ')')
		{
			if (numVisit)
			{
				numStack.push(curNum);
				curNum.first = 0, curNum.second = 0;
				numVisit = false;
			}
			pair<ll, ll> firstNum = numStack.top();
			numStack.pop();

			pair<ll, ll> secondNum = numStack.top();
			numStack.pop();

			pair<ll, ll> newNum;
			newNum.first = 0, newNum.second = 0;

			char oper = operStack.top();
			operStack.pop();

			if (oper == '#')
			{
				newNum.first = (getSharpResult({ firstNum.first, secondNum.first })) % mod1;
				newNum.second = (getSharpResult({ firstNum.second, secondNum.second })) % mod2;
				numStack.push(newNum);
			}
			else if (oper == '+')
			{
				newNum.first = (firstNum.first + secondNum.first) % mod1;
				newNum.second = (firstNum.second + secondNum.second) % mod2;
				numStack.push(newNum);
			}
			else
			{
				newNum.first = (firstNum.first * secondNum.first) % mod1;
				newNum.second = (firstNum.second * secondNum.second) % mod2;
				numStack.push(newNum);
			}
		}
	}

	if (numVisit) numStack.push(curNum);

	pair<ll, ll> result = numStack.top();

	if (group.find(result) == group.end()) group[result] = ++groupSz;
	return group[result];
}

int main()
{
	srand(time(NULL));

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		int N;

		cin >> N;
		groupSz = 0;
		group.clear();
		sharpResult.clear();

		vector<ll> output;

		for (int i = 0; i < N; i++)
		{
			cin >> input[i];
			output.push_back(registerStr(input[i]));
		}
		cout << "Case #" << tc << ": ";
		for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
		cout << "\n";
	}

	return 0;
}
