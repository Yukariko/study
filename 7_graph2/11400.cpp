#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int V, E;
vector<int> g[100001];
int c[100001];
int cnt;
vector<pair<int, int>> cut;

int dfs(int u, int p)
{
    c[u] = ++cnt;
    int ans = c[u];
    for (int v : g[u]) {
        if (!c[v]) {
            int vc = dfs(v, u);
            ans = min(ans, vc);
        } else if (p != v) {
            ans = min(ans, c[v]);
        }
    }
    if (ans > c[p]) cut.push_back({min(p, u), max(p, u)});
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> V >> E;
    for (int i=0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    c[1] = ++cnt;
    for (int v : g[1]) {
        if (!c[v]) {
            dfs(v, 1);
        }
    }

    sort(cut.begin(), cut.end());

    cout << cut.size() << endl;
    for (auto [u, v] : cut) cout << u << " " << v << endl;
    return 0;
}
