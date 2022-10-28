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

    vector<string> a(N);
    for (auto& s : a) {
        cin >> s;
    }

    vector<vector<bool>> visited(N, vector<bool>(M));
    queue<tuple<bool, int, int>> q;

    int sy, sx;
    for (int y=0; y < N; y++) {
        for (int x=0; x < M; x++) {
            if (a[y][x] == 'S') {
                sy = y;
                sx = x;
            } else if (a[y][x] == '*') {
                visited[y][x] = true;
                q.emplace(true, y, x);
            }
        }
    }

    visited[sy][sx] = true;
    q.emplace(false, sy, sx);

    int ans = 0;

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [c, y, x] = q.front();
            q.pop();

            if (!c && a[y][x] == 'D') {
                cout << ans << endl;
                return 0;
            }

            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) {
                    continue;
                }

                if (a[ny][nx] == 'X' || (c && a[ny][nx] == 'D')) {
                    continue;
                }

                visited[ny][nx] = true;
                q.emplace(c, ny, nx);
            }
        }
        ans++;
    }

    cout << "KAKTUS" << endl;

	return 0;
}
