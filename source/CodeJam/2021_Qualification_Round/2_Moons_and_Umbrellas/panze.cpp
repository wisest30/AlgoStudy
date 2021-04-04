#include <algorithm>
#include <array>
#include <cmath>
#include <functional> 
#include <iostream>
#include <iomanip>
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

string s;
vector<int> memo[2];

int n;
int cj;
int jc;

int Dp(int is_J, int now) {
  auto &ret = memo[is_J][now];

  if (ret != kInf) {
    return ret;
  }

  if (now == n) {
    ret = 0;
    return ret;
  }

  if (s[now + 1] == 'J') {
    if (is_J == 1) {
      ret = Dp(1, now + 1);
    } else {
      ret = Dp(1, now + 1) + cj;
    }
  } else if ((s[now + 1] == 'C')) {
    if (is_J == 1) {
      ret = Dp(0, now + 1) + jc;
    } else {
      ret = Dp(0, now + 1);
    }
  } else {
    if (is_J == 1) {
      ret = min(Dp(1, now + 1), Dp(0, now + 1) + jc);
    } else {
      ret = min(Dp(1, now + 1) + cj, Dp(0, now + 1));
    }
  }
  return ret;
}
void solve(int x, int y) {
  static int tc = 1;

  cj = x;
  jc = y;

  cin >> s;

  memo[0].clear();
  memo[1].clear();
  memo[0].resize(s.size(), kInf);
  memo[1].resize(s.size(), kInf);
  n = s.size() - 1;

  int ans;
  if (s[0] == '?') {
    ans = min(Dp(0, 0), Dp(1, 0));
  } else {
    ans = Dp(s[0] == 'J', 0);
  }

  LOGI << "Case #" << tc << ": " << ans;
  tc++;
}

int main(int argc, char** argv) {
  INIT_CODEFORCES();

  Solver::Run(&solve);

  return 0;
}
