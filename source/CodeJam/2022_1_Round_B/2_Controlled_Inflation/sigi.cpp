#include <bits/stdc++.h>


using namespace std;
long long dp[2];
int T;
int N,typeN;
long long  sol() {
	dp[0] = dp[1] = 0;
	long long lastVal[2] = { 0,0 };
	cin >> N;
	cin >> typeN;
	while(N--){
		long long lineMin = 1234567899;
		long long lineMax = -1;
		long long t;
		for(int i=0;i<typeN;i++){
			cin >> t;
			lineMin = min(t, lineMin);
			lineMax = max(t, lineMax);
		}
		long long thisDiff = (lineMax - lineMin);
		long long  nextdp[2];
		nextdp[0] = min(dp[0] + abs(lineMax - lastVal[0]), dp[1] + abs(lineMax - lastVal[1])) + thisDiff;
		nextdp[1] = min(dp[0] + abs(lineMin - lastVal[0]), dp[1] + abs(lineMin - lastVal[1])) + thisDiff;
		dp[0] = nextdp[0];
		dp[1] = nextdp[1];
		lastVal[0] = lineMin;
		lastVal[1] = lineMax;
	}
	return min(dp[0], dp[1]);

}
int main() {
	cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		cout << "Case #" << ti << ": ";
		cout << sol();
		cout << endl;
	}


}
