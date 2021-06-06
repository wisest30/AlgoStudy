// omit templates

#define MAX(A,B) ((A) < (B) ? (A) : (B))

namespace {
  using namespace std;

  constexpr bool kMultiTestCase = true;
  using Solver = predefined::Solver<kMultiTestCase>;

  constexpr int kInf = 0x7FFFFFFF;
}  // unnamed namespace;

vector<set<int>> stree, ktree;
set<int> visited;
stack<int> s;

void Dfs(int idx) {
  s.push(idx);
  visited.insert(idx);

  for (auto& child : stree[idx]) {
    const auto search = visited.find(child);
    if(search != visited.end()) stree[idx].erase(child);
  }

  for (const auto& node : ktree[idx]) {
    Dfs(node);
  }

  visited.erase(idx);
  s.pop();
}

int Dfs2(int idx) {
  int ret = 1;
  s.push(idx);
  visited.insert(idx);
  
  for (const auto& node : stree[idx]) {
    ret += Dfs2(node);
  }

  visited.erase(idx);
  s.pop();
  return ret;
}

void solve(int n) {
  stree.clear();
  stree.resize(n + 1);
  ktree.clear();
  ktree.resize(n + 1);
  visited.clear();

  for (int i = 2; i <= n; ++i) {
    int parent;
    cin >> parent;
    stree[parent].insert(i);
  }

  for (int i = 2; i <= n; ++i) {
    int parent;
    cin >> parent;
    ktree[parent].insert(i);
  }
  
  Dfs(1);

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    const auto search = visited.find(i);
    if (search != visited.end()) ans = MAX(ans, Dfs2(i));
  }

  LOGI << ans;
}

int main(int argc, char** argv) {
  INIT_CODEFORCES();

  Solver::Run(&solve);

  return 0;
}