#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, M;
	cin >> N >> M;

	int g[101][101];
	memset(g, 0x3f, sizeof(g));

	for (int i=1; i <= N; i++) {
		g[i][i] = 0;
	}

	for (int i=0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = min(g[u][v], w);
	}

	int d[101][101];
	int to[101][101];
	for (int i=1; i <= N; i++) {
		for (int j=1; j <= N; j++) {
			d[i][j] = g[i][j];
			to[i][j] = j;
		}
	}

	for (int k=1; k <= N; k++) {
		for (int i=1; i <= N; i++) {
			if (d[i][k] == INF) continue;
			for (int j=1; j <= N; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					to[i][j] = to[i][k];
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	for (int i=1; i <= N; i++) {
		for (int j=1; j <= N; j++) {
			cout << (d[i][j] == INF? 0: d[i][j]) << " ";
		}
		cout << endl;
	}
	for (int i=1; i <= N; i++) {
		for (int j=1; j <= N; j++) {
			if (d[i][j] == INF || i == j) {
				cout << 0 << endl;
				continue;
			}
			vector<int> path;
			for (int k=i; k != j; k=to[k][j]) {
				path.push_back(k);
			}
			path.push_back(j);
			cout << path.size() << " ";
			for (int p : path) {
				cout << p << " ";
			}
			cout << endl;
		}
	}


	return 0;
}
