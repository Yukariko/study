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
    queue<pair<int, int>> q;
    visited[0][0] = true;
    q.emplace(0, 0);

    int ans = 1;

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [y, x] = q.front();
            q.pop();

            if (y == N-1 && x == M-1) {
                cout << ans << endl;
                return 0;
            }

            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || a[ny][nx] != '1') {
                    continue;
                }

                visited[ny][nx] = true;
                q.emplace(ny, nx);
            }
        }
        ans++;
    }

	return 0;
}
