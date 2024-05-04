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
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> g(N + 1);
    for (int i=0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    const int INF = 1e9;
    vector<int> dist(N + 1, INF);
    vector<int> in_q(N + 1);
    queue<int> q;
    dist[1] = 0;
    in_q[1] = true;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        in_q[u] = false;

        for (auto& [v, w] : g[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (!in_q[v]) {
                    in_q[v] = true;
                    q.push(v);
                }
            }
        }
    }
    
    cout << dist[N] << endl;

    return 0;
}
