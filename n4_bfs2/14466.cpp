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
    int N, K, R;
    cin >> N >> K >> R;

    vector<vector<int>> a(N, vector<int>(N));
    vector<vector<int>> road(N, vector<int>(N));

    for (int i=0; i < R; i++) {
        int sy, sx, ey, ex;
        cin >> sy >> sx >> ey >> ex;
        sy--, sx--, ey--, ex--;

        for (int d = 0; d < 4; d++) {
            int ny = sy + dy[d];
            int nx = sx + dx[d];
            if (ny == ey && nx == ex) {
                road[sy][sx] |= 1 << d;
                road[ey][ex] |= 1 << (d ^ 1);
                break;
            }
        }
    }

    vector<pair<int, int>> cows(K);
    for (auto& [y, x] : cows) {
        cin >> y >> x;
        y--, x--;
        a[y][x] = 1;
    }

    int ans = 0;

    for (auto& [y, x] : cows) {
        vector<vector<bool>> visited(N, vector<bool>(N));
        queue<pair<int, int>> q;
        visited[y][x] = true;
        q.emplace(y, x);

        int meet_cows = 0;
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();

            if (a[y][x] == 1) {
                meet_cows++;
            }

            for (int d=0; d < 4; d++) {
                if (road[y][x] & (1 << d)) {
                    continue;
                }
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) {
                    continue;
                }

                visited[ny][nx] = true;
                q.emplace(ny, nx);
            }
        }

        ans += K - meet_cows;
    }

    ans /= 2;

    cout << ans << endl;

    return 0;
}
