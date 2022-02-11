#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, M;
	cin >> N >> M;

	int g[201][201];
	memset(g, 0x3f, sizeof(g));

	for (int i=1; i <= N; i++) {
		g[i][i] = 0;
	}

	for (int i=0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = min(g[u][v], w);
	}

	const int INF = 0x3f3f3f3f;
	int d[201][201];
	int to[201][201];

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
					d[i][j] = d[i][k] + d[k][j];
					to[i][j] = to[i][k];
				}
			}
		}
	}

	for (int i=1; i <= N; i++) {
		for (int j=1; j <= N; j++) {
			if (i == j || d[i][j] == INF) {
				cout << "- ";
			} else {
				cout << to[i][j] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
