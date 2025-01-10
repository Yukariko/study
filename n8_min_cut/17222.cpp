#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const ll INF = 1e18;

struct NetworkFlow {
    struct Edge {
        int v, rev;
        ll cap, flow;
        Edge(int v, int rev, ll cap, ll flow) : v(v), rev(rev), cap(cap), flow(flow) {}
    };

    int N;
    vector<vector<Edge>> g;

    NetworkFlow(int N) : N(N), g(N) {}

    void add_edge(int u, int v, ll capacity) {
        g[u].emplace_back(v, g[v].size(), capacity, 0);
        g[v].emplace_back(u, g[u].size() - 1, 0, 0);
    }

    ll calc_max_flow(int source, int sink) {

        ll total_flow = 0;

        while (true) {
            vector<pair<int, int>> from(N, make_pair(-1, -1));
            queue<int> q;
            from[source] = {source, 0};
            q.push(source);

            while (!q.empty() && from[sink].first == -1) {
                int u = q.front();
                q.pop();

                for (int i = 0; auto& [v, _, cap, flow] : g[u]) {
                    if (from[v].first == -1 && cap - flow > 0) {
                        from[v] = {u, i};
                        q.push(v);
                    }
                    i++;
                }
            }

            if (from[sink].first == -1) {
                break;
            }

            ll amount = INF;
            for (int u = sink; u != source; u = from[u].first) {
                auto [p, i] = from[u];
                amount = min(amount, g[p][i].cap - g[p][i].flow);
            }

            for (int u = sink; u != source; u = from[u].first) {
                auto [p, i] = from[u];
                int rev = g[p][i].rev;
                g[p][i].flow += amount;
                g[u][rev].flow -= amount;
            }

            total_flow += amount;
        }

        return total_flow;
    }
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    NetworkFlow nf(N + M + 2);
    int source = N + M;
    int sink = source + 1;
    vector<int> a(N), b(M);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        nf.add_edge(i, sink, INF);
    }

    for (int i = 0; i < M; i++) {
        cin >> b[i];
        nf.add_edge(source, N + i, b[i]);
    }

    for (int i = 0; i < M; i++) {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            int n;
            cin >> n;
            n -= 1;
            if (n < N) {
                nf.add_edge(i + N, n, a[n]);
            } else {
                nf.add_edge(i + N, n, min(b[i], b[n - N]));
            }
        }
    }

    cout << nf.calc_max_flow(source, sink) << endl;

    return 0;
}
