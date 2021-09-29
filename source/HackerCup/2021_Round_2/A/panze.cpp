#pragma warning (disable: 4996)

#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <vector>

using namespace std;
constexpr unsigned long long kMod = 1000000007;

struct Node {
  char type;
  int lcnt;
  int rcnt;
};

int main(int argc, char** argv) {
  freopen("input.txt", "r", stdin);
  ofstream fout("output.txt", ofstream::binary);

  int test_case;
  cin >> test_case;

  for (int tc = 1; tc <= test_case; ++tc) {
    int n, m;
    cin >> n >> m;
    vector<map<int,int>> fashions(n + 1);

    for (int i = 0; i < n + 1; ++i) {
      for (int j = 0; j < m; ++j) {
        int now;
        cin >> now;
        auto search = fashions[i].find(now);
        if (search == fashions[i].end()) fashions[i][now] = 0;
        fashions[i][now]++;
      }
    }

    map<int, int> changes;
    vector<int> cnts(n, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (auto f : fashions[i]) {
        auto search = fashions[i + 1].find(f.first);
        if (search == fashions[i + 1].end()) {
          cnts[i] += f.second;
          auto search_changes = changes.find(f.first);
          if (search_changes == changes.end()) {
            changes[f.first] = f.second;
          } else {
            changes[f.first] += f.second;
          }
        } else if (f.second > search->second) {
          const int diff = (f.second - search->second);
          cnts[i] += diff;
          auto search_changes = changes.find(f.first);
          if (search_changes == changes.end()) {
            changes[f.first] = diff;
          } else {
            search_changes->second += diff;
          }
        }
      }
      ans += cnts[i];
    }

    for (auto ff : fashions[0]) {
      auto search_changes = changes.find(ff.first);
      if (search_changes != changes.end()) {
        ans -= min(ff.second, search_changes->second);
      }
    }    

    fout << "Case #" << tc << ": " << ans << endl;
    cout << "Case #" << tc << ": " << ans << endl;
  }

  fout.close();

  return 0;
}