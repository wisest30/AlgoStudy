#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll T;
ll N;

void sol() {
	int res;
	for (int i = 1; i < N; i++) {
		int t;
		cout << "M " << i << " " << N << endl;
		cin >> t;
		if (i != t) {
			cout << "S " << i << " " << t << endl;
			cin >> res;
		}


	}
	cout << "D" << endl;
	
	cin >> res;

}
int main() {

	cin >> T;
	cin >> N;
	for (int i = 0; i < T; i++) {
		sol();
	}
}
