
#include <bits/stdc++.h>
#include <unordered_map>
#define INPUT
using namespace std;

int tc;

int Round;
int Model;



int solve() {
	unordered_map<int, int>haveChance;
	unordered_map<int, int>noChance;
	unordered_map<int, int>nextHaveChance;
	unordered_map<int, int>nextNoChance;
	int ret = 0;
	int temp;
	cin >> Round >> Model;
	for (int i = 0; i < Model; i++) {
		cin >> temp;
		haveChance[temp]++;
	}
	for (int i = 0; i < Round; i++) {
		vector<int>notPositioned;
		for (int j = 0; j < Model; j++) {
			cin >> temp;
			if (noChance[temp] > 0) {
				noChance[temp]--;
				nextNoChance[temp]++;
			}
			else if (haveChance[temp] > 0) {
				haveChance[temp]--;
				nextHaveChance[temp]++;
			}
			else {
				notPositioned.push_back(temp);
			}
		}
		int totalHave = 0;
		for (pair<int, int>  have : haveChance)
			totalHave += have.second;
		if(notPositioned.size()>totalHave)
			ret += notPositioned.size() - totalHave;
		haveChance.clear();
		noChance.clear();
		haveChance = nextHaveChance;
		noChance = nextNoChance;
		nextHaveChance.clear();
		nextNoChance.clear();
		for (int st : notPositioned)
			noChance[st]++;
		
	}
	return ret;
}

int main() {
#ifdef INPUT
	freopen("output.txt", "w", stdout);
	freopen("runway_input.txt", "r", stdin);
#endif
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cout << "Case #" << i << ": ";
		cout << solve() << endl;
	}
}

