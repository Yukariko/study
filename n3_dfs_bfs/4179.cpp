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

    int R, C;
    cin >> R >> C;

    vector<string> a(R);
    for (string& s : a) {
        cin >> s;
    }

    vector<vector<bool>> visited(R, vector<bool>(C));
    queue<pair<int, int>> q;

    auto push = [&](int y, int x) {
        visited[y][x] = true;
        q.emplace(y, x);
    };

    for (int i=0; i < R; i++) {
        for (int j=0; j < C; j++) {
            if (a[i][j] == 'F') {
                push(i, j);
            }
        }
    }

    for (int i=0; i < R; i++) {
        for (int j=0; j < C; j++) {
            if (a[i][j] == 'J') {
                push(i, j);
            }
        }
    }

    int fsz = q.size() - 1, jsz = 1;
    int ans = 1;
    while (!q.empty()) {
        while (fsz--) {
            auto [y, x] = q.front();
            q.pop();

            for (int d=0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny < 0 || ny >= R || nx < 0 || nx >= C || a[ny][nx] == '#' || visited[ny][nx]) {
                    continue;
                }
                push(ny, nx);
            }
        }
        fsz = q.size() - jsz;
        while (jsz--) {
            auto [y, x] = q.front();
            q.pop();

            if (y == 0 || y == R - 1 || x == 0 || x == C - 1) {
                cout << ans << endl;
                return 0;
            }

            for (int d=0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny < 0 || ny >= R || nx < 0 || nx >= C || a[ny][nx] == '#' || visited[ny][nx]) {
                    continue;
                }
                push(ny, nx);
            }

        }
        jsz = q.size() - fsz;

        ans++;
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
