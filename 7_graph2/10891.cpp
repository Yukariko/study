#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int V, E;
vector<int> g[100001];
int c[100001];
int cnt;
bool cactus = true;

int dfs(int u)
{
    c[u] = ++cnt;
    int ans = c[u];
    int up = 0;
    bool down = 0;
    for (int v : g[u]) {
        if (!c[v]) {
            int vc = dfs(v);
            ans = min(ans, vc);
            if (c[u] > vc) {
                up++;
            }
        } else if (c[u] <= c[v]) {
            down = true;
        } else {
            up++;
            ans = min(ans, c[v]);
        }
    }
    if (up >= 2 && down) {
        cactus = false;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> V >> E;
    for (int i=0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    c[1] = ++cnt;
    int cycles = 0;
    for (int v : g[1]) {
        if (!c[v]) {
            dfs(v);
        } else {
            cycles++;
        }
    }
    if (cycles >= 2) {
        cactus = false;
    }
    if (cactus) cout << "Cactus" << endl;
    else cout << "Not cactus" << endl;

    return 0;
}


