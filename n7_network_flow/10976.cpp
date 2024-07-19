#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int INF = 1e9;

struct NetworkFlow {
    int N;
    vector<vector<int>> cap, flow;

    NetworkFlow(int N) : N(N), cap(N, vector<int>(N)), flow(N, vector<int>(N)) {}

    void add_edge(int u, int v, int capacity) {
        cap[u][v] = capacity;
    }

    int calc_max_flow(int source, int sink) {

        int total_flow = 0;

        while (true) {
            vector<int> from(N, -1);
            queue<int> q;
            from[source] = source;
            q.push(source);

            while (!q.empty() && from[sink] == -1) {
                int u = q.front();
                q.pop();

                for (int v = 0; v < N; v++) {
                    if (from[v] == -1 && cap[u][v] - flow[u][v] > 0) {
                        from[v] = u;
                        q.push(v);
                    }
                }
            }

            if (from[sink] == -1) {
                break;
            }

            int amount = INF;
            for (int u = sink; u != source; u = from[u]) {
                amount = min(amount, cap[from[u]][u] - flow[from[u]][u]);
            }


            for (int u = sink; u != source; u = from[u]) {
                flow[from[u]][u] += amount;
                flow[u][from[u]] -= amount;
            }

            total_flow += amount;
        }

        return total_flow;
    }

};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        NetworkFlow nf(N);
        for (int i=0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            u -= 1, v -= 1;
            if (u == 0 || v == N - 1) {
                nf.add_edge(u, v, 1);
            } else {
                nf.add_edge(u, v, 1);
            }
        }

        cout << nf.calc_max_flow(0, N - 1) << endl;
    }

	return 0;
}
