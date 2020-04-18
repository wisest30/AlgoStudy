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
 
const ll mod[2] = { 998244353, 1000000007 };
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int N;
	string ans = "";
 
	cin >> N;
	cin >> ans;
 
	for (int i = 1; i < N; ++i)
	{
		string temp;
		cin >> temp;
 
		int mx_same_len = 0;
		ll hash_front[2]{};
		ll hash_back[2]{};
		ll mul[2] = { 1, 1 };
 
		for (int j = 0;; ++j)
		{
			if (j >= temp.size()) break;
			if ((int)ans.size() - 1 - j < 0) break;
			
			hash_back[0] = (hash_back[0] * 17LL + temp[j]) % mod[0];
			hash_back[1] = (hash_back[1] * 71LL + temp[j]) % mod[1];
			hash_front[0] = ((ans[ans.size() - 1 - j] * mul[0]) % mod[0] + hash_front[0]) % mod[0];
			hash_front[1] = ((ans[ans.size() - 1 - j] * mul[1]) % mod[1] + hash_front[1]) % mod[1];
 
			mul[0] = (mul[0] * 17LL) % mod[0];
			mul[1] = (mul[1] * 71LL) % mod[1];
 
			if (hash_back[0] == hash_front[0] && hash_back[1] == hash_front[1]) mx_same_len = j + 1;
		}
 
		ans += temp.substr(mx_same_len, temp.size());
	}
 
	cout << ans << "\n";
 
	return 0;
}
