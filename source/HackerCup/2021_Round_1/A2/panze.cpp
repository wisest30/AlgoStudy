#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
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
    int n;
    string str;
    cin >> n >> str;

    vector<Node> nodes;

    Node now;
    now.type = 0;
    now.lcnt = 0;
    now.rcnt = 0;
    int fcnt = 0;
    for (const char c : str) {
      switch (c) {
        case 'F': {
          fcnt++;
          break;
        }
        case 'O':
        case 'X': {
          if (now.type != c) {
            if (now.type != 0) {
              nodes.push_back(now);
              nodes.back().rcnt += fcnt;
            }
            now.type = c;
            now.lcnt = fcnt + 1;
            now.rcnt = 1;
          } else {
            now.lcnt += fcnt + 1;
            now.rcnt += fcnt + 1;
          }
          fcnt = 0;
          break;
        }
        default: {
          break;
        }
      }
    }
    nodes.push_back(now);
    nodes.back().rcnt += fcnt;

    unsigned long long cnt = 0;
    unsigned long long sum = 0;

    for (int i = nodes.size() - 1; i >= 1; --i) {
      sum += nodes[i].rcnt;
      cnt += sum;
    }
    vector<unsigned long long> sums(nodes.size(), 0);
    for (int i = 1; i < nodes.size(); ++i) {
      sums[i] = sum;
      sum -= nodes[i].rcnt;
    }

    unsigned long long ans = 0;
    for (int i = 0; i < nodes.size() - 1; ++i) {
      ans += nodes[i].lcnt * cnt;
      ans %= kMod;
      cnt -= sums[i+1];
    }

    fout << "Case #" << tc << ": " << ans << endl;
    cout << "Case #" << tc << ": " << ans << endl;
  }

  fout.close();

  return 0;
}