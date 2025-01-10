#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int INF = 2e9;

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

    void print_min_cut(int source) {
        queue<int> q;
        vector<bool> visited(N);
        visited[source] = true;
        q.push(source);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto& [v, _, cap, flow] : g[u]) {
                if (visited[v] || cap == flow) {
                    continue;
                }
                visited[v] = true;
                q.push(v);
            }
        }

        for (int i = 0; i < N / 2; i++) {
            if (visited[i] && !visited[i + N / 2]) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int source, sink;
    cin >> source >> sink;
    source -= 1;
    sink -= 1;
    sink += N;

    NetworkFlow nf(N * 2);
    vector<int> toll(N);
    for (int i = 0; i < N; i++) {
        cin >> toll[i];
        nf.add_edge(i, i + N, toll[i]);
    }

    for (int i=0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        nf.add_edge(u + N, v, INF);
        nf.add_edge(v + N, u, INF);
    }

    nf.calc_max_flow(source, sink);

    nf.print_min_cut(source);

    return 0;
}
