#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAX_N = 50;
constexpr int MAX_V = 2 * MAX_N + 2;
constexpr int source = 100, sync = 101;
int n, m, max_flow;
int F[MAX_V][MAX_V], C[MAX_V][MAX_V];
vector<int> G[MAX_V];

void solve(int TestCase)
{
    cin >> n >> m;

    // set capacity
    for (auto i = 0; i < n; ++i)
    {
        cin >> C[source][i];
        max_flow += C[source][i];
    }
    int su = 0;
    for (auto i = 0; i < m; ++i)
    {
        cin >> C[MAX_N + i][sync];
        su += C[MAX_N + i][sync];
    }
    if (su != max_flow)
    {
        cout << -1 << endl;
        return;
    }
    for (auto i = 0; i < n; ++i)
        for (auto j = 0; j < m; ++j)
            C[i][MAX_N + j] = 1;

    // set edges
    for (auto i = 0; i < n; ++i)
        G[source].push_back(i);
    for (auto i = 0; i < n; ++i)
    {
        for (auto j = 0; j < m; ++j)
        {
            G[i].push_back(MAX_N + j);
            G[MAX_N + j].push_back(i);
        }
    }
    for (auto i = 0; i < m; ++i)
        G[MAX_N + i].push_back(sync);

    // maximum flow
    int flow_sum = 0;
    while (true)
    {
        auto prev = vector<int>(MAX_V, -1);
        stack<int> st;
        st.push(source);
        while (!st.empty())
        {
            auto cur = st.top();
            st.pop();
            if (cur == sync)
                break;
            for (auto nxt : G[cur])
            {
                if (prev[nxt] != -1)
                    continue;
                if (F[cur][nxt] >= C[cur][nxt])
                    continue;
                prev[nxt] = cur;
                st.push(nxt);
            }
        }

        if (prev[sync] == -1)
            break;

        auto cur = sync;
        while (cur != source)
        {
            F[prev[cur]][cur]++;
            F[cur][prev[cur]]--;
            cur = prev[cur];
        }
        flow_sum++;
    }

    if (flow_sum != max_flow)
    {
        cout << -1 << endl;
        return;
    }

    // re-ordering
    for (auto i = 0; i < n; ++i)
    {
        for (auto j = 0; j < m; ++j)
        {
            if (!F[i][MAX_N + j])
                continue;

            auto prev = vector<int>(MAX_V, -1);
            stack<int> st;
            st.push(i);
            while (!st.empty())
            {
                auto cur = st.top();
                st.pop();
                if (cur == MAX_N + j)
                    break;
                for (auto nxt : G[cur])
                {
                    if (nxt < i)
                        continue;
                    if (cur == i && nxt <= MAX_N + j)
                        continue;
                    if (prev[nxt] != -1)
                        continue;
                    if (F[cur][nxt] >= C[cur][nxt])
                        continue;
                    prev[nxt] = cur;
                    st.push(nxt);
                }
            }

            if (prev[MAX_N + j] == -1)
                continue;

            F[i][MAX_N + j] = F[MAX_N + j][i] = 0;
            auto cur = MAX_N + j;
            while (cur != i)
            {
                F[prev[cur]][cur]++;
                F[cur][prev[cur]]--;
                cur = prev[cur];
            }
        }
    }

    // print
    for (auto i = 0; i < n; ++i)
    {
        for (auto j = 0; j < m; ++j)
            cout << F[i][MAX_N + j];
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    for (auto i = 1; i <= t; ++i)
    {
        // cout << "Case #"<< i << ": ";
        solve(i);
    }
}
