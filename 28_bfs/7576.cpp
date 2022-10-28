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
    cin >> M >> N;

    vector<vector<int>> a(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M));
    queue<pair<int, int>> q;

    int cnt = 0;
    for (int i=0; i < N; i++) {
        for (int j=0; j < M; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                visited[i][j] = true;
                q.emplace(i, j);
            } else if (a[i][j] == 0) {
                cnt++;
            }
        }
    }

    if (cnt == 0) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [y, x] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || a[ny][nx] != 0) {
                    continue;
                }

                cnt--;
                visited[ny][nx] = true;
                q.emplace(ny, nx);
            }
        }
        ans++;
    }

    if (cnt == 0) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

	return 0;
}
