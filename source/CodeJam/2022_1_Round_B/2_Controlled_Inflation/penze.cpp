#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main () {
  freopen("input.txt","r", stdin);
  int tc;
  cin >> tc;

  for (int t = 1; t <= tc; t++) {
    int n, p;
    cin >> n >> p;

    vector<pair<ll,ll>> v(n, pair<ll,ll>(1e9, 0));
    vector<vector<ll>> memo(2, vector<ll>(n));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < p; j++) {
        ll tmp;
        cin >> tmp;
        v[i].first = min(v[i].first, tmp);
        v[i].second = max(v[i].second, tmp);
      }
    }

    v[0].first = v[0].second;
    memo[0][0] = memo[1][0] = v[0].second;

    for (int i = 1; i < n; i++) {
      ll to_min_cand1 = memo[0][i-1] + abs(v[i - 1].first - v[i].second) + abs(v[i].second - v[i].first);
      ll to_min_cand2 = memo[1][i-1] + abs(v[i - 1].second - v[i].second) + abs(v[i].second - v[i].first);
      memo[0][i] = min(to_min_cand1, to_min_cand2);

      ll to_max_cand1 = memo[0][i-1] + abs(v[i - 1].first - v[i].first) + abs(v[i].second - v[i].first);
      ll to_max_cand2 = memo[1][i-1] + abs(v[i - 1].second - v[i].first) + abs(v[i].second - v[i].first);
      memo[1][i] = min(to_max_cand1, to_max_cand2);
    }

    cout << "Case #" << t << ": " << min(memo[0][n-1], memo[1][n-1]) << endl;
  }
  return 0;
}


