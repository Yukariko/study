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
    int N, M, K, X;
    cin >> N >> M >> K >> X;

    vector<vector<int>> g(N + 1);
    for (int i=0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    queue<int> q;
    vector<int> d(N+1, -1);
    d[X] = 0;
    q.push(X);

    bool found = false;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (d[v] != -1) continue;
            d[v] = 1 + d[u];
            if (d[v] == K) {
                found = true;
                continue;
            }
            q.push(v);
        }
    }

    if (!found) {
        cout << -1 << endl;
        return 0;
    }

    for (int i=1; i <= N; i++) {
        if (d[i] == K) {
            cout << i << endl;
        }
    }

    return 0;
}
