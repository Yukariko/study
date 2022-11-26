#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int N;
int a[101][101];
int b[101][101];
pair<int, int> visited[101][101];

void marking(int y, int x, int mark)
{
	vector<vector<bool>> _visited(N, vector<bool>(N));
	queue<pair<int, int>> q;
	_visited[y][x] = true;
	q.emplace(y, x);

	while (!q.empty()) {
		auto [y, x] = q.front();
		q.pop();

		b[y][x] = mark;

		bool adj_sea = false;

		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N || _visited[ny][nx]) {
				continue;
			}

			if (a[ny][nx] == 0) {
				adj_sea = true;
				continue;
			}

			_visited[ny][nx] = true;
			q.emplace(ny, nx);
		}

		if (adj_sea) {
			visited[y][x] = {mark, 0};
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;

	for (int i=0; i < N; i++) {
		for (int j=0; j < N; j++) {
			cin >> a[i][j];
		}
	}

	int cnt = 0;
	for (int i=0; i < N; i++) {
		for (int j=0; j < N; j++) {
			if (a[i][j] == 1 && b[i][j] == 0) {
				marking(i, j, ++cnt);
			}
		}
	}

	queue<tuple<int, int, int>> q;
	for (int i=0; i < N; i++) {
		for (int j=0; j < N; j++) {
			if (visited[i][j].first != 0) {
				q.emplace(visited[i][j].first, i, j);
			}
		}
	}

	int dist = 0;
	int ans = N * 2;
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			auto [m, y, x] = q.front();
			q.pop();

			for (int d=0; d < 4; d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];

				if (ny < 0 || ny >= N || nx < 0 || nx >= N || a[ny][nx] != 0) {
					continue;
				}

				auto [nm, nd] = visited[ny][nx];

				if (nm > 0 && nm != m) {
					ans = min(ans, nd + dist);
					continue;
				}

				if (nm == m) {
					continue;
				}

				visited[ny][nx] = {m, dist + 1};
				q.emplace(m, ny, nx);
			}
		}
		dist++;
	}

	cout << ans << endl;

	return 0;
}
