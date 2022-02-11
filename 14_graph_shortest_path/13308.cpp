#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

ll dijkstra(const vector<vector<pair<int, int>>>& g, const vector<int>& o)
{
	const ll INF = 1e15;
	const int N = g.size() - 1;
	vector<vector<ll>> d(2501, vector<ll>(g.size(), INF));
	priority_queue<tuple<ll, int, int>> pq;
	d[o[1]][1] = 0;
	pq.emplace(0, o[1], 1);

	while (!pq.empty()) {
		auto [cost, min_oil, u] = pq.top();
		pq.pop();
		cost = -cost;

		if (u == N) {
			return d[min_oil][N];
		}

		if (d[min_oil][u] < cost) continue;

		for (auto& [v, w] : g[u]) {
			int next_oil = min(min_oil, o[v]);
			if (d[next_oil][v] > cost + w * min_oil) {
				d[next_oil][v] = cost + w * min_oil;
				pq.emplace(-d[next_oil][v], next_oil, v);
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

	vector<int> o(V + 1);
	for (int i=1; i <= V; i++)
		cin >> o[i];

	vector<vector<pair<int, int>>> g(V + 1);
	for (int i=0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}

	cout << dijkstra(g, o) << endl;

	return 0;
}
