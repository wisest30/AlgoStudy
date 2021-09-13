#include <bits/stdc++.h>
#define INPUT
#define A2
using namespace std;
int tc;
int N;
const int MOD = 1e9 + 7;
int solve() {
	cin >> N;
	string input;
	cin >> input;
	vector<pair<int,int>>interval;
	char prev = 0;
	int prevIdx = -1;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 'X' || input[i] == 'O') {
			if (input[i] != prev) {
				prev = input[i];
				interval.push_back({ i,i }); 
			}
			else {
				interval.back().second = i;
			}

		}
	}
	vector<pair<int, int>>LRPair;
	for (int i = 0; i < interval.size(); i++) {
		int lastElem = -1;
		if (i > 0) lastElem = interval[i - 1].second;
		int nextElem = input.size();
		if (i < interval.size() - 1)nextElem = interval[i + 1].first;
		LRPair.push_back({ interval[i].second - lastElem, nextElem - interval[i].first });
	}


	long long ret = 0;
	long long sum = 0;
	long long rPara = 0;
	for (int i = LRPair.size() - 1; i > 0; i--) {
		
		sum = (sum + LRPair[i].second) % MOD; 
		rPara = (rPara + sum) % MOD; //d+2e
		ret = (ret+1LL* LRPair[i-1].first * rPara) % MOD;
	}
	return ret%MOD;


}

int main() {
#ifdef INPUT
	freopen("output.txt", "w", stdout);
	freopen("weak_typing_chapter_2_input.txt", "r", stdin);
#endif
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cout << "Case #" << i << ": ";
		cout << solve();
		cout << endl;
	}
}

