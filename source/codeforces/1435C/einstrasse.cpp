#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define endl '\n'
 
 
int main() {
 
	ll a[6];
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	int n;
	cin >> n;
	vector<ll> b(n);
	vector<ll> cnts(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	vector<pii> arr(n * 6);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			auto& item = arr[i * 6 + j];
			item.first = b[i] - a[j];
			item.second = i;
		}
	}
	sort(arr.begin(), arr.end());
	int left, right;
	left = right = 0; //inclusive 범위
	cnts[arr[0].second]++;
	int zero = n - 1;
	ll ans = 2e9;
	//two pointer
	while (right < arr.size() && left <= right) {
		if (zero == 0) {
			ans = min(ans, arr[right].first - arr[left].first);
		}
 
		if (right + 1 < arr.size() && zero > 0) {
			//모자란 경우
			right++;
			if (cnts[arr[right].second] == 0) zero--;
			cnts[arr[right].second]++;
			
		} else {
			//과한경우
			cnts[arr[left].second]--;
			if (cnts[arr[left].second] == 0) zero++;
			left++;
 
		}
 
	}
	cout << ans << endl;
	return 0;
}