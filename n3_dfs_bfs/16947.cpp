#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

vector<int> g[3001];
int dist[3001];
bool visited[3001];
queue<int> q;

int dfs(int u, int p)
{
    if (visited[u]) {
        return u;
    }
    visited[u] = true;
    for (int v : g[u]) {
        if (v == p) {
            continue;
        }

        int cycle = dfs(v, u);
        if (cycle > 0) {
            q.push(u);
            dist[u] = 0;
            if (cycle == u) {
                return 0;
            }
            return cycle;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;

    for (int i=0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    fill(&dist[1], &dist[N + 1], -1);

    dfs(1, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (dist[v] != -1) {
                continue;
            }
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    for (int i=1; i <= N; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
