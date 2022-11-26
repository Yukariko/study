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
	int T;
	cin >> T;

	while (T--) {
		int H, W, O, F;
		int XS, XE, YS, YE;
		cin >> H >> W >> O >> F;
		cin >> XS >> YS >> XE >> YE;
		XS--, YS--, XE--, YE--;
		swap(H, W);

		vector<vector<int>> a(H, vector<int>(W));

		for (int i=0; i < O; i++) {
			int X, Y, L;
			cin >> X >> Y >> L;
			X--, Y--;
			a[Y][X] = L;
		}


		vector<vector<bool>> visited(H, vector<bool>(W));
		queue<pair<int, int>> q;

		visited[YS][XS] = true;
		q.emplace(YS, XS);

		int dist = 0;
		while (!q.empty()) {
			int sz = q.size();
			int force = F - dist;
			while (sz--) {
				auto [y, x] = q.front();
				q.pop();

				if (y == YE && x == XE) {
					cout << "잘했어!!" << endl;
					goto next;
				}

				for (int d=0; d < 4; d++) {
					int ny = y + dy[d];
					int nx = x + dx[d];

					if (ny < 0 || ny >= H || nx < 0 || nx >= W || visited[ny][nx]) {
						continue;
					}

					if (force < a[ny][nx] - a[y][x]) {
						continue;
					}

					visited[ny][nx] = true;
					q.emplace(ny, nx);
				}
			}
			dist++;
			if (dist > F) {
				break;
			}
		}

		cout << "인성 문제있어??" << endl;
next:
		(void)0;
	}

	return 0;
}
