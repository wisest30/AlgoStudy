#include <bits/stdc++.h>


using namespace std;
deque<int> dq;
int T;
int N;
void sol() {
	cin >> N;
	dq.clear();
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		dq.emplace_back(temp);
	}
	int ret = 0;
	int localMax = -1;
	while (dq.size() > 0) {
		int localMin;
		if (dq.front() < dq.back()) {
			localMin = dq.front();
			if (localMax <= localMin) {
				ret++;
				localMax = localMin;
			}
			dq.pop_front();
		}
		else {
			localMin = dq.back();
			if (localMax <= localMin) {
				ret++;
				localMax = localMin;
			}
			dq.pop_back();
		}
	}
	cout << ret;
	return;

}
int main() {
	cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		cout << "Case #" << ti << ": ";
		sol();
		cout << endl;
	}


}
