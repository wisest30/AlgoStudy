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

int main(int argc, char** argv) {
  freopen("input.txt", "r", stdin);
  ofstream fout("output.txt", ofstream::binary);

  int test_case;
  cin >> test_case;

  for (int tc = 1; tc <= test_case; ++tc) {
    int n;
    string str;
    cin >> n >> str;

    char now = 0;
    int ans = -1;
    for (const char c : str) {
      switch (c) {
        case 'F':
        {
          break;
        }
        case 'O':
        case 'X':
        {
          ans += (now != c);
          now = c;
          break;
        }
        default:
        {
          break;
        }
      }
    }
    if (ans == -1) ans = 0;

    
    fout << "Case #" << tc << ": " << ans << endl;
    cout << "Case #" << tc << ": " << ans << endl;
  }

  fout.close();

  return 0;
}