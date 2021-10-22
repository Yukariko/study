#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int V, E;
vector<int> g[10001];
vector<vector<int>> scc;
stack<int> st;
int c[10001];
bool checked[10001];
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
            checked[v] = true;
            if (v == u) break;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> V >> E;
    for (int i=0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for (int i=1; i <= V; i++) {
        if (!c[i]) {
            dfs(i);
        }
    }

    for (auto& vec : scc) sort(vec.begin(), vec.end());
    sort(scc.begin(), scc.end());

    cout << scc.size() << endl;
    for (auto& vec : scc) {
        for (int u : vec) cout << u << " ";
        cout << "-1" << endl;
    }
    return 0;
}
