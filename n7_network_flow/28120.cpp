#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int INF = 1e9;

struct NetworkFlow {
    struct Edge {
        int v, cap, flow, rev;
        Edge(int v, int cap, int flow, int rev) : v(v), cap(cap), flow(flow), rev(rev) {}
    };

    int N;
    vector<vector<Edge>> g;

    NetworkFlow(int N) : N(N), g(N) {}

    void add_edge(int u, int v, int capacity) {
        g[u].emplace_back(v, capacity, 0, g[v].size());
        g[v].emplace_back(u, 0, 0, g[u].size() - 1);
    }

    int calc_max_flow(int source, int sink) {

        int total_flow = 0;

        for (int iter = 0; iter < g[source].size(); iter++) {
            vector<pair<int, int>> from(N, make_pair(-1, -1));
            queue<int> q;
            from[source] = {source, 0};
            from[g[source][iter].v] = {source, iter};
            q.push(g[source][iter].v);

            while (!q.empty() && from[sink].first == -1) {
                int u = q.front();
                q.pop();

                for (int i = 0; auto& [v, cap, flow, _] : g[u]) {
                    if (from[v].first == -1 && cap - flow > 0) {
                        from[v] = {u, i};
                        q.push(v);
                    }
                    i++;
                }
            }

            if (from[sink].first == -1) {
                continue;
            }

            int amount = INF;
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

    int N, K, X;
    cin >> N >> K >> X;

    NetworkFlow nf(N + K + 2);
    int source = N + K;
    int sink = N + K + 1;
    for (int i = 0; i < K; i++) {
        nf.add_edge(N + i, sink, X);
    }

    for (int i = 0; i < N; i++) {
        int CN;
        cin >> CN;
        for (int j = 0; j < CN; j++) {
            int C;
            cin >> C;
            C -= 1;
            nf.add_edge(i, N + C, 1);
        }
    }

    vector<pair<int, int>> b(N);
    for (int i = 0; auto& [n, idx] : b) {
        cin >> n;
        idx = i;
        i++;
    }

    sort(b.begin(), b.end(), [](const auto& p, const auto& q) { return p.first > q.first; });

    for (auto& [_, i] : b) {
        nf.add_edge(source, i, 1);
    }

    nf.calc_max_flow(source, sink);
    vector<vector<int>> group(K);
    for (int i = 0; i < N; i++) {
        for (auto& [v, cap, flow, _] : nf.g[i]) {
            if (flow > 0) {
                group[v - N].push_back(i);
            }
        }
    }

    for (auto& v : group) {
        cout << v.size();
        for (auto& n : v) {
            cout << " " << n + 1;
        }
        cout << endl;
    }

    return 0;
}
