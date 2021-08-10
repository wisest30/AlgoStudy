#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl '\n'


void solve() {
	ll n, m;
	cin >> n >> m;
	if (n == 0) {
		cout << (m + 1) << endl;
		return;
	}
	else if (n > m) {
		cout << 0 << endl;
		return;
	}
	m++;
	ll ans = 0;
	//m > n인 경우 m+1와 n를 비트단위로 비교를 한다.
	/*
	10011111101111110010 -> m+1 (654322)
	   11110001001000000 -> n (123456)

	101 -> m+1 (5)
	 11 -> n (3)
	위의 m+1의 값은 계속 커질 수 있고 결국 위아래를 xor한 최소값을
	구해야 한다.
	*/
	for (int i = 31; i >= 0; i--) {
		ll p = (1LL << i);
		ll mv = (p&m);
		ll nv = (p&n);
		if (mv) {
			if (!nv) //m+1만 1인 경우 값을 더할 수 밖에 없다.
				ans += mv;
			//둘다 1인 경우, xor해서 0이 되므로 더할 필요가 없다.
		}
		else if (nv) break;
		// m+1의 경우 0이고 n이 1인 경우, m+1에 숫자를 더해서
		// 해당 값을 1로 바꾸고 뒤에 모든 수를 다 맞춰줄 수 있기
		// 때문에 더이상 값을 더할 필요는 없다.
	}
	cout << ans << endl;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) solve();
}
