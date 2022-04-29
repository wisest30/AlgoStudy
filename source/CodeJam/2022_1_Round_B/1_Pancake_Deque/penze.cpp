#include <bits/stdc++.h>

using namespace std;

int main () {
  freopen("input.txt","r", stdin);
  int tc;
  cin >> tc;

  for (int t = 1; t <= tc; t++) {
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    int left_max = 0, right_max = 0;
    int left = 0, right = 0;

    for (int i = 0; i < n; i++) {
      if(v[i] >= left_max) {
        left_max = v[i];
        left++;
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      if(v[i] >= right_max) {
        right_max = v[i];
        right++;
      }
    }

    int max_cnt = 0;

    for (int i = n - 1; i >= 0; i--) {
      if(v[i] == left_max) {
        max_cnt++;
      }
    }
    cout << "Case #" << t << ": " << right + left - max_cnt << endl;
  }
  return 0;
}


