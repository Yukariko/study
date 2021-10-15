#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> g(V + 1);
        for (int i=0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        const int red = 1;
        const int black = 2;
        vector<int> colors(V + 1);
        for (int u=1; u <= V; u++) {
            if (colors[u]) continue;
            queue<int> q;
            colors[u] = red;
            q.push(u);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                int color = colors[u];
                for (int v : g[u]) {
                    if (colors[v] == color) {
                        cout << "NO" << endl;
                        goto next;
                    }
                    if (!colors[v]) {
                        colors[v] = color == red? black: red;
                        q.push(v);
                    }
                }
            }
        }
        cout << "YES" << endl;
next:
        (void)0;
    }

    return 0;
}
