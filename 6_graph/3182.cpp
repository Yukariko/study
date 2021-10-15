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
    int N;
    cin >> N;

    vector<int> g(N);
    for (int& n : g) { cin >> n; n--; }

    int ans = N;
    int max_cnt = 0;
    for (int i=0; i < N; i++) {
        int u = i;
        int cnt = 1;

        vector<bool> visited(N);
        while (!visited[u]) {
            visited[u] = true;
            cnt++;
            u = g[u];
        }
        if (max_cnt < cnt) {
            ans = i + 1;
            max_cnt = cnt;
        }
    }

    cout << ans << endl;
    
    return 0;
}
