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
        int N, M, T;
        cin >> N >> M >> T;

        int S, G, H;
        cin >> S >> G >> H;

        vector<vector<pair<int, int>>> g(N + 1);
        for (int i=0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }

        vector<int> candidates(T);
        for (auto& candidate : candidates) {
            cin >> candidate;
        }
        sort(candidates.begin(), candidates.end());

        const int INF = 1e9;
        vector<int> dist(N + 1, INF);
        vector<int> in_q(N + 1);
        vector<bool> from_gh(N + 1);
        queue<int> q;
        dist[S] = 0;
        in_q[S] = true;
        q.push(S);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            in_q[u] = false;

            for (auto& [v, w] : g[u]) {
                if (dist[u] + w <= dist[v]) {
                    if (!from_gh[u] && from_gh[v] && dist[u] + w < dist[v]) {
                        from_gh[v] = false;
                    }
                    dist[v] = dist[u] + w;
                    if ((u == G && v == H) || (u == H && v == G) || from_gh[u]) {
                        from_gh[v] = true;
                    }
                    if (!in_q[v]) {
                        in_q[v] = true;
                        q.push(v);
                    }
                }
            }
        }

        for (int candidate: candidates) {
            if (from_gh[candidate]) {
                cout << candidate << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
