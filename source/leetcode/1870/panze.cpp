#include <cmath>
using namespace std;

class Solution {
public:
  bool check(vector<int>& dist, double hour, double velocity) {
    double h = 0.0;
    for (int i = 0; i < dist.size() - 1; ++i) {
      h += ceil(dist[i] / velocity);
    }
    h += dist[dist.size() - 1] / velocity;

    return h > hour;
  }

  int minSpeedOnTime(vector<int>& dist, double hour) {
    if (dist.size() > ceil(hour)) return -1;

    int l = 1;
    int r = 1e7;

    while (l < r) {
      int mid = (l + r) / 2;

      if (check(dist, hour, mid)) {
        l = mid + 1;
      }
      else {
        r = mid;
      }
    }

    return l;
  }
};