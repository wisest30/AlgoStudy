#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sol() {
	map<ll, ll> m;
	ll N, C;
	cin >> N >> C;
	vector<ll>st;
	vector<ll>en;

	for (int i = 0; i < N; i++) {
		ll t_st, t_en;
		cin >> t_st >> t_en;
		if (t_st < t_en - 1) {
			st.push_back(t_st + 1);
			en.push_back(t_en);
		}
	}
	sort(st.begin(), st.end());
	sort(en.begin(), en.end());
	ll st_i = 0, en_i = 0;
	ll last_st = st[0];
	int h = 0;
	while (1) {
		if (en_i == en.size())break;
		if ((st_i < st.size() && st[st_i] < en[en_i]))
		{
			if (h > 0)
				m[h] += st[st_i] - last_st;
			last_st = st[st_i];
			h++;
			st_i++;
		}
		else if (st_i < st.size() && st[st_i] == en[en_i]) {
			st_i++, en_i++;
		}
		else {
			m[h] += en[en_i] - last_st;
			last_st = en[en_i];
			h--;
			en_i++;
		}
	}
	ll ret = N;
	for (auto iter = m.rbegin(); iter != m.rend(); iter++) {
		if (iter->second >= C) {
			ret += iter->first*C;
			return ret;
		}
		else {
			ret += iter->first*iter->second;
			C -= iter->second;
		}
	}
	return ret;



}

int main() {
	int TC;
	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		ll ret = sol();
		cout << "Case #" << i << ": ";

		cout << ret << endl;
	}


}
