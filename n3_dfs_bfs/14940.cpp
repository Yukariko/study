#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M;
    cin >> N >> M;

    vector<vector<int>> a(N, vector<int>(M));
    for (auto& v : a) {
        for (auto& n : v) {
            cin >> n;
        }
    }

    vector<vector<int>> dist(N, vector<int>(M, -1));
    int gy = -1, gx = -1;
    for (int i=0; i < N; i++) {
        for (int j=0; j < M; j++) {
            if (a[i][j] == 2) {
                gy = i;
                gx = j;
            } else if (a[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }

    queue<pair<int, int>> q;
    dist[gy][gx] = 0;
    q.emplace(gy, gx);

    int cur_dist = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto [y, x] = q.front();
            q.pop();

            for (int d=0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (ny < 0 || ny >= N || nx < 0 || nx >= M || dist[ny][nx] != -1) {
                    continue;
                }

                dist[ny][nx] = cur_dist + 1;
                q.emplace(ny, nx);
            }
        }
        cur_dist++;
    }

    for (auto& v : dist) {
        for (auto n : v) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}
