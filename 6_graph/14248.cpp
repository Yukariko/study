#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int N, S;
int g[100001];
bool visited[100001];

int dfs(int u)
{
    if (u < 1 || u > N || visited[u]) return 0;
    visited[u] = true;
    return 1 + dfs(u - g[u]) + dfs(u + g[u]);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for (int u=1; u <= N; u++) {
        int v;
        cin >> v;
        g[u] = v;
    }
    cin >> S;

    cout << dfs(S) << endl;
    return 0;
}
