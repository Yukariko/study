#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int N, M, K;
int a[21][21];
int d[401][401];

void bfs(int no, int sy, int sx)
{
    vector<vector<bool>> visited(N, vector<bool>(N));
    queue<pair<int, int>> q;
    visited[sy][sx] = true;
    q.emplace(sy, sx);

    int dist = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto [y, x] = q.front();
            q.pop();

            if (a[y][x] > 1) {
                int idx = a[y][x] - 2;
                d[no][idx] = dist;
            }

            for (int i=0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= N || nx < 0 || nx >= N || a[ny][nx] == 1) {
                    continue;
                }

                if (visited[ny][nx]) {
                    continue;
                }

                visited[ny][nx] = true;
                q.emplace(ny, nx);
            }
        }
        dist++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> K;

    for (int i=0; i < N; i++) {
        for (int j=0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    int ey, ex;
    cin >> ey >> ex;
    ey--, ex--;

    auto goals = vector<tuple<int, int, int, int>>(M);

    for (int i = 0; auto& [sy, sx, ey, ex] : goals) {
        cin >> sy >> sx >> ey >> ex;
        sy--, sx--, ey--, ex--;
        a[sy][sx] = 2 + i;
        i++;
    }

    memset(d, -1, sizeof(d));
    for (int i=0; i < M; i++) {
        auto& [sy, sx, ey, ex] = goals[i];
        bfs(i, ey, ex);
    }

    bfs(M, ey, ex);

    int fuel = K;
    vector<bool> visited(M);
    int cur = M;

    for (int i=0; i < M; i++) {
        int next = -1;
        for (int j=0; j < M; j++) {
            if (visited[j] || d[cur][j] == -1) {
                continue;
            }
            if (next == -1 || d[cur][next] > d[cur][j]) {
                next = j;
            } else if (d[cur][next] == d[cur][j] && goals[next] > goals[j]) {
                next = j;
            }
        }
        if (next == -1) {
            fuel = -1;
            break;
        }
        if (d[cur][next] > fuel) {
            fuel = -1;
            break;
        }
        fuel -= d[cur][next];
        if (d[next][next] == -1 || fuel < d[next][next]) {
            fuel = -1;
            break;
        }
        fuel += d[next][next];
        cur = next;
        visited[cur] = true;
    }

    cout << fuel << endl;
    return 0;
}
