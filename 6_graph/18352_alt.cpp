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
    vector<bool> visited(N + 1);
    visited[X] = true;
    q.push(X);

    int d = 0;
    while (!q.empty() && d < K) {
        int sz = q.size();
        while (sz--) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (visited[v]) continue;
                visited[v] = true;
                q.push(v);
            }
        }
        d++;
    }

    if (q.empty()) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> ans;
    while (!q.empty()) {
        ans.push_back(q.front());
        q.pop();
    }
    sort(ans.begin(), ans.end());

    for (int n : ans) cout << n << endl;

    return 0;
}
