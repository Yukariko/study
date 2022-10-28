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

    vector<vector<vector<bool>>> visited(2, vector<vector<bool>>(N, vector<bool>(M)));
    queue<tuple<bool, int, int>> q;
    visited[0][0][0] = true;
    q.emplace(false, 0, 0);

    int ans = 1;

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [c, y, x] = q.front();
            q.pop();

            if (y == N-1 && x == M-1) {
                cout << ans << endl;
                return 0;
            }
            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
                    continue;
                }

                bool nc = c || a[ny][nx] == '1';
                if (visited[nc][ny][nx] || (c && a[ny][nx] == '1')) {
                    continue;
                }

                visited[nc][ny][nx] = true;
                q.emplace(nc, ny, nx);
            }
        }
        ans++;
    }

    cout << -1 << endl;

	return 0;
}

