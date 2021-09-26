#include <bits/stdc++.h>


using namespace std;
int N;
void solve() {
	string inp;
	cin >> N;
	cin >> inp;
	vector<int>trashCan(N, 0);
	for (int i = 0; i < N; i++)
		if (inp[i] == '1')
			trashCan[i] = 1;


	vector<int>minDist(N, INT_MAX);
	int prevTrashCan = -2 * N;
	for (int i = 0; i < N; i++) {
		if (trashCan[i] == 1)
			prevTrashCan = i;
		minDist[i] = min(minDist[i], i - prevTrashCan);
	}
	 prevTrashCan = 3* N;
	int ret = 0;
	for (int i = N-1; i >=0 ; i--) {
		if (trashCan[i] == 1)
			prevTrashCan = i;
		minDist[i] = min(minDist[i], prevTrashCan-i);
		ret += minDist[i];
	}
	
	cout << ret;
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
