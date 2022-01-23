typedef long long ll;

class Solution {
public:
	vector<ll> batteries;
	int n;

	bool valid(ll runTime)
	{
		vector<ll> batteries;

		batteries = this->batteries;

		ll sum = 0;

		for (auto& battery : batteries)
		{
			sum += min(battery, runTime);
		}

		return sum >= n * runTime;
	}

	long long maxRunTime(int n, vector<int>& batteries) {
		for (int battery : batteries) this->batteries.push_back(1LL * battery);
		this->n = n;

		ll hi = 1e14;
		ll lo = 1;

		ll ans = -1;

		while (lo <= hi)
		{
			ll mid = lo + (hi - lo) / 2;

			if (valid(mid))
			{
				ans = mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}

		return ans;
	}
};
