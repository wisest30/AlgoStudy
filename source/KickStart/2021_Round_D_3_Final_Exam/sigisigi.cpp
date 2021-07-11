#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, ll> m;



void sol() {
	m.clear();
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		ll A, B;
		cin >> A >> B;
		m[A] = B;
	}
	vector<ll> ret_vec;
	for (int i = 0; i < M; i++) {
		ll student;
		cin >> student;
		auto iter=m.upper_bound(student);
		ll next_candidate = -1;
		if (iter != m.end()) {
			next_candidate = iter->first;
		}
		if (iter == m.begin()) {
			ll ret = iter->first;
			if (iter->first != iter->second)
				m[iter->first + 1] = iter->second;
			m.erase(iter);
			cout << ret << " ";
			continue;
		}
		iter--;
		if (iter->first <= student && iter->second >= student) {
			if (iter->first == iter->second) {
				m.erase(iter);
			}
			else {
				if (iter->first == student) {
					m[student + 1] = iter->second;
					m.erase(iter);
				}
				else if (iter->second == student) {
					m[iter->first] = student - 1;
				}
				else {
					m[student + 1] = iter->second;
					m[iter->first] = student - 1;
				}
			}
			cout << student << " "; 
		}
		else {
			ll before_candidate = iter->second;
			ll ret;
			if (next_candidate == -1 || next_candidate - student >= student - before_candidate) {
				ret = iter->second;
				if (iter->first == iter->second)m.erase(iter);
				else iter->second--;
			}
			else {
				iter++;
				ret = iter->first;
				if (iter->first != iter->second)
					m[iter->first + 1] = iter->second;
				m.erase(iter);
				
			}
			cout << ret << " ";
		}
	}
	cout << endl;
}

int main() {
	int TC;
	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		cout << "Case #" << i << ": ";
		sol();
		
	}


}
