#include <algorithm>
#include <array>
#include <cmath>
#include <functional> 
#include <iostream>
#include <memory>
#include <numeric>
#include <queue>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <vector>

namespace predefined {

#ifdef CODEFORCES_DEBUG
  constexpr bool kIsDebug = true;
#else
  constexpr bool kIsDebug = false;
#endif

enum class LogType {
  INFO,
  DEBUG
};

template <LogType Type, bool... Bools>
struct Log;

template <>
struct Log<LogType::INFO> {
  Log() {}
  ~Log() { std::cout << '\n'; }

  template <typename T>
  Log& operator<< (const T &t) {
    std::cout << t;
    return *this;
  }
};

template <>
struct Log<LogType::DEBUG, true>{
  Log() {}
  ~Log() { std::cout << '\n'; }

  void Open() {
    freopen("input.txt", "r", stdin);
  }

  template <typename T>
  Log& operator<< (const T &t) {
    std::cout << t;
    return *this;
  }
};

template <>
struct Log<LogType::DEBUG, false> {
  Log() {}
  ~Log() {}

  void Open() {}

  template <typename T>
  Log& operator<< (const T &t) { return *this; }
};

namespace solver {

template <class Arg>
void GetArg(Arg& value) {
  std::cin >> value;
}

template <size_t index, class... Args>
typename std::enable_if<index == sizeof...(Args)>::type
GetArgsImpl(std::tuple<Args...>& args) {}

template <size_t index, class... Args>
typename std::enable_if<(index < sizeof...(Args))>::type
GetArgsImpl(std::tuple<Args...>& args) {
  GetArg(std::get<index>(args));
  GetArgsImpl<index + 1>(args);
}

template<typename ... Args>
std::tuple<Args...> GetArgs() {
  std::tuple<Args...> args;

  GetArgsImpl<0>(args);

  return args;
}

template<int...> struct IndexTuple {};

template<int I, typename T, typename... Types> 
struct MakeIndexesImpl; 

template<int I, int... Indexes, typename T, typename ... Types> 
struct MakeIndexesImpl<I, IndexTuple<Indexes...>, T, Types...> 
{ 
  typedef typename MakeIndexesImpl<I + 1, IndexTuple<Indexes..., I>, Types...>::type type; 
};

template<int I, int... Indexes> 
struct MakeIndexesImpl<I, IndexTuple<Indexes...> > 
{ 
  typedef IndexTuple<Indexes...> type; 
};

template<typename ... Types> 
struct MakeIndexes : MakeIndexesImpl<0, IndexTuple<>, Types...> 
{};

template<class... Args, int... Indexes > 
void RunImpl(void (*func)(Args...), std::tuple<Args...>&& args, IndexTuple< Indexes... >) 
{ 
  func(std::forward<Args>( std::get<Indexes>(args))... ); 
} 

template<class ... Args> 
void RunImpl(void (*func)(Args...), const std::tuple<Args...>& args) {
  RunImpl(func, std::tuple<Args...>(args), typename MakeIndexes<Args...>::type());
}

template<typename ... Args>
void Run(void (*func)(Args...)) {
  std::tuple<Args...> args = GetArgs<Args...>();

  RunImpl(func, args);;
}

template <typename T>
std::size_t GetTestCaseCount();

template <>
std::size_t GetTestCaseCount<std::true_type>() {
  std::size_t test_case_count;
  std::cin >> test_case_count;
  return test_case_count;
}

template <>
std::size_t GetTestCaseCount<std::false_type>() {
  return 1;
}

} // solver

template <bool MultiTest>
struct Solver {
  constexpr static bool condition = MultiTest | kIsDebug;
  typedef typename std::conditional<condition, std::true_type, std::false_type>::type run_type;

  template <typename ... Args>
  static void Run(void (*func)(Args...)) {
    auto tc_count = solver::GetTestCaseCount<run_type>();
    while (tc_count--) solver::Run(func);
  }
};

template<typename T>
struct BoolMap {
  explicit BoolMap(const T &_true_value, const T &_false_value) 
      : true_value(_true_value),
        false_value(_false_value) {}

  const T inline GetValue(const bool bool_key) const {
    return bool_key ? true_value : false_value;  
  };

  const T true_value;
  const T false_value;
};

}  // predefined;

#define LOGI predefined::Log<predefined::LogType::INFO>()
#define LOGD predefined::Log<predefined::LogType::DEBUG, predefined::kIsDebug>()
#define LABEL(variable_name) #variable_name << ": " << variable_name << " "

#define INIT_ANSWER(type, true_value, false_value) \
  const predefined::BoolMap<type> predefined_bool_map(true_value, false_value)
#define INIT_STRING_ANSWER(true_string, false_string) \
  INIT_ANSWER(std::string, true_string, false_string)
#define GET_ANSWER(bool_key) \
  predefined_bool_map.GetValue(bool_key)

#define INIT_CODEFORCES() \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL); \
  LOGD.Open();

namespace {
using namespace std;

constexpr bool kMultiTestCase = true;
using Solver = predefined::Solver<kMultiTestCase>;

constexpr int kInf = 0x7FFFFFFF;
}  // unnamed namespace;

int t, n, q;

vector<int> tool_answer;
vector<int> sorted_tool_answer;
int tool_t;
int tool_q;
void ToolInit(int t, int n, int q) {
  tool_answer.clear();
  tool_t = t;
  tool_q = q / tool_t;

  vector<int> candi;
  for (int i = 1; i <= n; ++i) {
    candi.push_back(i);
  }

  tool_answer.push_back(-1);
  for (int i = 0; i < n; ++i) {
    int index = rand() % (n - i);
    tool_answer.push_back(candi[index]);
    candi.erase(candi.begin() + index);
  }

  sorted_tool_answer = tool_answer;
  sort(sorted_tool_answer.begin(), sorted_tool_answer.end());
}

int ToolAsk(int a, int b, int c) {
  if (--tool_q < 0) {
    LOGD << "tool_q is empty";
    return -1;
  }
  if(tool_answer[a] < tool_answer[b] && tool_answer[b] < tool_answer[c] ||
     tool_answer[c] < tool_answer[b] && tool_answer[b] < tool_answer[a]) return b;
  if(tool_answer[a] < tool_answer[c] && tool_answer[c] < tool_answer[b] ||
     tool_answer[b] < tool_answer[c] && tool_answer[c] < tool_answer[a]) return c;
  if(tool_answer[b] < tool_answer[a] && tool_answer[a] < tool_answer[c] ||
     tool_answer[c] < tool_answer[a] && tool_answer[a] < tool_answer[b]) return a;
  return -1;
}

bool ToolSubmit(vector<int> &ans) {
  if (ans.size() != sorted_tool_answer.size() - 1) {
    LOGD << "answer size is wrong";
    return false;
  }

  for (int i = 1; i < tool_answer.size(); ++i) {
    if (tool_answer[ans[i - 1]] == sorted_tool_answer[i] || tool_answer[ans[i - 1]] == sorted_tool_answer[tool_answer.size() - i]) continue;
    else {
      return false;
    }
  }
  return true;
}

int Ask(int a, int b, int c) {
  int mid;
  if (predefined::kIsDebug) {
    mid = ToolAsk(a, b, c);
  } else {
    cout << a << " " << b << " " << c;
    cin >> mid;
  }

  return mid;
}

int Submit(vector<int> &ans) {
  int success;
  if (predefined::kIsDebug) {
    success = ToolSubmit(ans) ? 1 : -1;
  } else {
    for (const auto &a : ans) {
      cout << a << " ";
    }
    cout << endl;
    cin >> success;
  }

  LOGD << LABEL(success);
  return success;
}

void dq(vector<int> &buf, const int start, const int end, const int left_index, const int right_index) {
  const int left_value = buf[left_index];
  const int right_value = buf[right_index];

  if (end - start == 2) {
    buf[start] = left_value;
    buf[start + 1] = right_value;
    return;
  }

  vector<int> lvec(0);
  vector<int> mvec(0);
  vector<int> rvec(0);

  for (int i = start; i < end; ++i) {
    if (left_index == i || right_index == i) continue;
    
    int mid = Ask(buf[i], left_value, right_value);
    if (mid == left_value) {
      lvec.push_back(buf[i]);
    } else if (mid == right_value) {
      rvec.push_back(buf[i]);
    } else {
      mvec.push_back(buf[i]);
    }
  }

  int now = start;
  for (const auto &l : lvec) {
    buf[now++] = l;
  }
  buf[now++] = left_value;
  for (const auto &m : mvec) {
    buf[now++] = m;
  }
  buf[now++] = right_value;
  for (const auto &r : rvec) {
    buf[now++] = r;
  }

  now = start;
  if (lvec.size() >= 2) {
    int mid = Ask(buf[now], buf[now + 1], left_value);
    if (buf[now + 1] == mid) {
      dq(buf, now, now + lvec.size(), now, now + 1);
    } else {
      dq(buf, now, now + lvec.size(), now + 1, now);
    }
  } 
  now += lvec.size() + 1;

  if (mvec.size() >= 2) {
    int mid = Ask(buf[now], buf[now + 1], right_value);
    if (buf[now + 1] == mid) {
      dq(buf, now, now + mvec.size(), now, now + 1);
    } else {
      dq(buf, now, now + mvec.size(), now + 1, now);
    }
  } 
  now += mvec.size() + 1;

  if (rvec.size() >= 2) {
    int mid = Ask(right_value, buf[now], buf[now + 1]);
    if (buf[now] == mid) {
      dq(buf, now, now + rvec.size(), now, now + 1);
    } else {
      dq(buf, now, now + rvec.size(), now + 1, now);
    }
  }
}

void solve() {
  if (predefined::kIsDebug) ToolInit(t, n, q);

  vector<int> ans;
  for(int i = 1; i <= n; ++i) {
    ans.push_back(i);
  }

  dq(ans, 0, ans.size(), 0, 1);

  Submit(ans);
}

int main(int argc, char** argv) {
  freopen("input.txt", "r", stdin);

  cin >> t >> n >> q;

  for (int i = 0; i < t; ++i) {
    solve();
  }

  return 0;
}
