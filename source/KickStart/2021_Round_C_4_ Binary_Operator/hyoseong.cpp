#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MOD = 998694751;

int parse_num(stack<char>& st) {
    string s;
    while(!st.empty() && st.top() >= '0' && st.top() <= '9') {
        s.push_back(st.top());
        st.pop();
    }

    reverse(s.begin(), s.end());
    ll ret = 0;
    for(auto c : s) {
        ret = ret * 10 + c - '0';
        ret %= MOD;
    }

    return ret;
}

int calculate(ll a, ll b, char op) {
    if(op == '+')
        return (a + b) % MOD;
    else if(op == '*')
        return a * b % MOD;
    else { // '#'
        auto ha = ((382818284ll * (a + 582648173ll)) ^ 384729472) % MOD;
        auto hb = ((473558583ll * (b + 746363826ll)) ^ 573627374) % MOD;
        return ((383727282ll * ha + 583726283) ^ (182748472ll * hb + 382738342)) % MOD;
    }
}

int f(string_view s) {
    stack<char> st;
    for(auto c : s) {
        if(c == ')') {
            auto a = parse_num(st);
            char op = st.top();
            st.pop();
            auto b = parse_num(st);

            assert(st.top() == '(');
            st.pop();
            auto res = calculate(a, b, op);
            for(auto x : to_string(res))
                st.push(x);
        }
        else
            st.push(c);
    }

    return parse_num(st);
}

void solve(int TestCase) {
    int n;
    cin >> n;

    map<int, int> m;
    vector<int> ret(n);
    for(auto i = 0; i < n; ++i) {
        string s;
        cin >> s;

        auto val = f(s);
        if(m.find(val) == m.end())
            m[val] = m.size() + 1;

        ret[i] = m[val];
    }

    for(auto x : ret)
        cout << x << " ";
    cout << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        cout << "Case #"<< i << ": ";
        solve(i);
    }
}
