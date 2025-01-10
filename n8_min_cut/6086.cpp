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
        int v, rev, cap, flow;
        Edge(int v, int rev, int cap, int flow) : v(v), rev(rev), cap(cap), flow(flow) {}
    };

    int N;
    vector<vector<Edge>> g;

    NetworkFlow(int N) : N(N), g(N) {}

    void add_edge(int u, int v, int capacity) {
        g[u].emplace_back(v, g[v].size(), capacity, 0);
        g[v].emplace_back(u, g[u].size() - 1, 0, 0);
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

    int N;
    cin >> N;

    NetworkFlow nf(52);
    int source = 0;
    int sink = 25;
    for (int i = 0; i < N; i++) {
        char u, v;
        int n;
        cin >> u >> v >> n;
        if (u >= 'a') {
            u -= 'a';
            u += 26;
        } else {
            u -= 'A';
        }
        if (v >= 'a') {
            v -= 'a';
            v += 26;
        } else {
            v -= 'A';
        }
        nf.add_edge(u, v, n);
        nf.add_edge(v, u, n);
    }

    cout << nf.calc_max_flow(source, sink) << endl;

    return 0;
}
