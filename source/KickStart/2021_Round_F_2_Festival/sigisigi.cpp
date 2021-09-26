#include <bits/stdc++.h>


using namespace std;
int Day, N, K;
void solve() {
	cin >> Day >> N >> K;
	vector<pair<int, int>> attrEvent;
	for (int i = 0; i < N; i++) {
		int happy, st, en;
		cin >> happy >> st >> en;
		attrEvent.push_back({ st,happy });
		attrEvent.push_back({ en + 1,-1 * happy });
	}
	sort(attrEvent.begin(), attrEvent.end());

	long long  sumOfCurrentHappy = 0;
	long long maxOfHappy = 0;
	multiset<int>outK, inK;
	for (int i = 0; i < attrEvent.size(); i++) {
		if (attrEvent[i].second > 0) {
			int happy = attrEvent[i].second;
			if (inK.size() >= K) {
				auto iter = inK.begin();
				if (*iter < happy) {
					sumOfCurrentHappy -= *iter;
					outK.insert(*iter);
					inK.erase(iter);
					sumOfCurrentHappy += happy;
					inK.insert(happy);
				}
				else {
					outK.insert(happy);
				}
			}
			else {
				sumOfCurrentHappy += happy;
				inK.insert(happy);
			}
		}
		else {
			int happy = -1 * attrEvent[i].second;
			if (inK.count(happy)) {
				auto iter = inK.find(happy);
				sumOfCurrentHappy -= *iter;
				inK.erase(iter);
				if (outK.size()) {
					auto iter2 = outK.end();
					iter2--;
					sumOfCurrentHappy += *iter2;
					inK.insert(*iter2);
					outK.erase(iter2);

				}
			}
			else {
				auto iter = outK.find(happy);
				outK.erase(iter);
			}
		}
		if (i == attrEvent.size() - 1 || attrEvent[i].first < attrEvent[i + 1].first)
			maxOfHappy = max(maxOfHappy, sumOfCurrentHappy);

	}
	cout << maxOfHappy;



}

int main() {
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
		cout << endl;
	}


}
