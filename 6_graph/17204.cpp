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
    int N, K;
    cin >> N >> K;

    vector<int> g(N);
    for (int& n : g) cin >> n;

    vector<bool> visited(N);
    int u = 0;
    int m = 0;
    while (!visited[u] && u != K) {
        visited[u] = true;
        m++;
        u = g[u];
    }

    if (u == K) {
        cout << m << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
