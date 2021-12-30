#include <iostream>
#include <cstdio>
using namespace std;
 
using ll = long long;
constexpr int INF = 987654321;
void solve() {
	int n;
	string src, dst;
	cin >> n >> src >> dst;
	int src1, src0, dst1, dst0;
	src1 = src0 = dst1 = dst0 = 0;
	for (int i = 0; i < n; i++) {
		if (src[i] == '1') {
			src1++;
		}
		else {
			src0++;
		}
		if (dst[i] == '1') {
			dst1++;
		}
		else {
			dst0++;
		}
	}
	int ans = INF;
	if (src1 == dst1) { //짝수번 스왑했을때 맞는 경우
		int outofpos = 0;
		for (int i = 0; i < n; i++) {
			if (src[i] != dst[i]) outofpos++;
		}
		if (outofpos % 2 == 0) {
			ans = min(ans, outofpos);
		}
	}
 
	if (src1 == dst0 + 1) { //홀수번 스왑했을때 맞는 경우
		int outofpos = 0;
		for (int i = 0; i < n; i++) {
			if (src[i] == dst[i]) outofpos++; //negation한거랑다른거니 == 로 비교함.
		}
		if (outofpos % 2 == 1) {
			ans = min(ans, outofpos);
		}
	}
 
	cout << (ans == INF ? -1 : ans) << endl;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) solve();
	return 0;
}
