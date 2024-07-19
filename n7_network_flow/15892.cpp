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

        while (true) {
            vector<pair<int, int>> from(N, make_pair(-1, -1));
            queue<int> q;
            from[source] = {source, 0};
            q.push(source);

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
                break;
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

    int N, M;
    cin >> N >> M;

    NetworkFlow nf(N * 2 + 2);
    int source = 0;
    int sink = N - 1;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a -= 1, b -= 1;
        nf.add_edge(a, b, c);
        nf.add_edge(b, a, c);
    }

    cout << nf.calc_max_flow(source, sink) << endl;

    return 0;
}

