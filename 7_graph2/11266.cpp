#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int V, E;
vector<int> g[10001];
int c[10001];
int cnt;
vector<int> cut;

int dfs(int u)
{
    c[u] = ++cnt;
    int ans = c[u];
    bool find = false;
    for (int v : g[u]) {
        if (!c[v]) {
            int vc = dfs(v);
            ans = min(ans, vc);
            if (c[u] <= vc) find = true;
        } else {
            ans = min(ans, c[v]);
        }
    }
    if (find) cut.push_back(u);
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

    for (int u=1; u <= V; u++) {
        if (c[u] == 0) {
            c[u] = ++cnt;
            int nc = 0;
            for (int v : g[u]) {
                if (!c[v]) {
                    nc++;
                    dfs(v);
                }
            }
            if (nc >= 2) cut.push_back(u);
        }
    }

    sort(cut.begin(), cut.end());

    cout << cut.size() << endl;
    for (int u : cut) cout << u << " ";
    cout << endl;

    return 0;
}
