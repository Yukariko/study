#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int V, E;
vector<int> g[20001];
vector<vector<int>> scc;
stack<int> st;
int c[20001];
int checked[20001];
int cnt;

int dfs(int u)
{
    c[u] = ++cnt;
    int res = c[u];
    st.push(u);

    for (int v : g[u]) {
        if (!c[v]) {
            int vc = dfs(v);
            res = min(res, vc);
        } else if (!checked[v]) {
            res = min(res, c[v]);
        }
    }

    if (res == c[u]) {
        scc.push_back(vector<int>());
        while (true) {
            int v = st.top();
            st.pop();
            scc.back().push_back(v);
            checked[v] = scc.size();
            if (v == u) break;
        }
    }
    return res;
}

int in(int u)
{
    return u + V;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> V >> E;
    for (int i=0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g[in(-u)].push_back(in(v));
        g[in(-v)].push_back(in(u));
    }

    for (int i=-V; i <= V; i++) {
        if (i == 0) continue;
        int u = in(i);
        if (!c[u]) {
            dfs(u);
        }
    }

    for (int i=1; i <= V; i++) {
        if (checked[in(i)] == checked[in(-i)]) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}
