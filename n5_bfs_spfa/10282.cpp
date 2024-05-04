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
        int N, D, C;
        cin >> N >> D >> C;

        vector<vector<pair<int, int>>> g(N + 1);
        for (int i=0; i < D; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            g[v].emplace_back(u, w);
        }

        const int INF = 1e9;
        vector<int> dist(N + 1, INF);
        vector<int> in_q(N + 1);
        queue<int> q;
        dist[C] = 0;
        in_q[C] = true;
        q.push(C);

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
        
        int n_c = 0, m_d = 0;
        for (int i=1; i <= N; i++) {
            if (dist[i] == INF) continue;
            n_c++;
            m_d = max(m_d, dist[i]);
        }
        cout << n_c << " " << m_d << endl;
    }

    return 0;
}

