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
    int N, L;
    cin >> N >> L;

    vector<vector<int>> stations(N + 1);
    vector<vector<int>> routes(L + 1);
    vector<int> idx(N + 1);

    for (int i=1; i <= L; i++) {
        while (1) {
            int u;
            cin >> u;
            if (u == -1) {
                break;
            }
            stations[u].push_back(i);
            routes[i].push_back(u);
        }
    }

    int src, dst;
    cin >> src >> dst;

    if (src == dst) {
        cout << 0 << endl;
        return 0;
    }

    vector<bool> visited_stations(N + 1);
    vector<bool> visited_routes(L + 1);
    queue<int> q;
    int ans = 0;

    visited_stations[src] = true;
    q.push(src);

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int u = q.front();
            q.pop();

            for (int r : stations[u]) {
                if (visited_routes[r]) {
                    continue;
                }
                visited_routes[r] = true;
                for (int v : routes[r]) {
                    if (v == dst) {
                        cout << ans << endl;
                        return 0;
                    }

                    if (visited_stations[v]) continue;
                    visited_stations[v] = true;
                    q.push(v);
                }
            }
        }
        ans++;
    }


    cout << -1 << endl;
    return 0;
}
