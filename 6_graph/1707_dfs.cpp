#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int red = 1;
const int black = 2;

int V, E;
vector<vector<int>> g;
vector<int> colors;

bool dfs(int u, int c)
{
    colors[u] = c;
    int nc = c == red? black: red;
    for (int v : g[u]) {
        if (colors[v] == c || (!colors[v] && !dfs(v, nc))) {
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> V >> E;

        g.clear();
        g.resize(V + 1);
        for (int i=0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        colors.clear();
        colors.resize(V + 1);
        bool matched = true;
        for (int u=1; u <= V; u++) {
            if (!colors[u] && !dfs(u, red)) {
                matched = false;
                break;
            }
        }

        if (matched) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
