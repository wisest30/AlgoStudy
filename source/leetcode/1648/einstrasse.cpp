typedef long long ll;

class Solution {
	const ll MOD = 1e9 + 7;
public:
	int maxProfit(vector<int>& inventory, int orders) {
		ll ans = 0;
		vector<int>& arr = inventory;
		vector<ll> sum;
		sum.push_back(0);
		sort(arr.begin(), arr.end());
		for (int item : arr) {
			sum.push_back(sum.back() + item);
		}
		ll left = 0;
		ll right = 1e9+10; //[left, right] 범위?
		//ll right = 10; //[left, right] 범위?
		while (left < right) {
			ll mid = (left + right + 1) / 2; // mid 이상인 값으로만 만들거임
			ll idx = upper_bound(arr.begin(), arr.end(), mid) - arr.begin(); //mid 이상인 인덱스가 나옴
			ll num = sum.back() - sum[idx] - ((arr.size() - idx) * mid);
			if (num >= orders) {
				left = mid;
			}
			else {
				right = mid - 1;
			}
		}
		ll pivot = left + 1; // pivot보다 양많은거를 다 사버릴거임
		for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
			if (*it <= pivot) break;
			ans += (pivot + 1 + *it) * (*it - pivot) / 2 % MOD;
			ans %= MOD;
			orders -= *it - pivot;
		}
		ans += orders * pivot % MOD;
		ans %= MOD;

		return ans;
	}
};
