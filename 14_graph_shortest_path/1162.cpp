#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

ll dijkstra(const vector<vector<pair<int, int>>>& g, int K)
{
	const ll INF = 1e10;
	const int N = g.size() - 1;
	vector<vector<ll>> d(K + 1, vector<ll>(g.size(), INF));
	priority_queue<tuple<ll, int, int>> pq;
	d[0][1] = 0;
	pq.emplace(0, 0, 1);

	while (!pq.empty()) {
		auto [cost, covered, u] = pq.top();
		pq.pop();
		cost = -cost;

		if (u == N) {
			return cost;
		}

		if (d[covered][u] < cost) continue;

		for (auto& [v, w] : g[u]) {
			if (d[covered][v] > cost + w) {
				d[covered][v] = cost + w;
				pq.emplace(-d[covered][v], covered, v);
			}
			if (covered < K && d[covered + 1][v] > cost) {
				d[covered + 1][v] = cost;
				pq.emplace(-d[covered + 1][v], covered + 1, v);
			}
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int V, E;
	cin >> V >> E;

	int K;
	cin >> K;

	vector<vector<pair<int, int>>> g(V + 1);
	for (int i=0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}

	cout << dijkstra(g, K) << endl;

	return 0;
}
