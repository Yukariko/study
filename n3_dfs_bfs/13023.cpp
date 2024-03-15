#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

bool visited[2000];
vector<int> g[2000];

bool dfs(int u, int c)
{
    if (c == 4) {
        return true;
    }
    visited[u] = true;
    for (int v : g[u]) {
        if (visited[v]) {
            continue;
        }

        if (dfs(v, c + 1)) {
            visited[u] = false;
            return true;
        }
    }
    visited[u] = false;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for (int i=0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i=0; i < N; i++) {
        if (dfs(i, 0)) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}
