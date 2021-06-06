// omit templates

namespace {
  using namespace std;

  constexpr bool kMultiTestCase = false;
  using Solver = predefined::Solver<kMultiTestCase>;

  constexpr int kInf = 0x7FFFFFFF;
  constexpr int kMod = 998244353;
}  // unnamed namespace;

long long dp[1000001];
long long sum[1000001];
long long cnt[1000001];
void solve(int n) {
  cnt[1] = 1;
  for (int i = 2; i <= n; ++i) {
    cnt[i] += 2;
    for (int j = 2; i * j <= n; ++j) {
      cnt[i * j]++;
    }
  }

  for (int i = 1; i <= n; ++i) {
    dp[i] = (cnt[i] + sum[i - 1]) % kMod;
    sum[i] = (dp[i] + sum[i - 1]) % kMod;
  }

  LOGI << dp[n];
}

int main(int argc, char** argv) {
  INIT_CODEFORCES();

  Solver::Run(&solve);

  return 0;
}