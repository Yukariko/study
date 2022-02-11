#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int dijkstra(vector<vector<pair<int, int>>>& g, int S, int D)
{
	const int INF = 1e9;
	vector<int> d(g.size(), INF);
	priority_queue<pair<int, int>> pq;
	d[S] = 0;
	pq.emplace(0, S);

	vector<vector<int>> from(g.size());

	while (!pq.empty()) {
		auto [c, u] = pq.top();
		pq.pop();
		c = -c;

		if (d[u] < c) continue;

		for (auto [v, w] : g[u]) {
			if (d[v] > c + w) {
				d[v] = c + w;
				pq.emplace(-d[v], v);
				from[v].clear();
				from[v].push_back(u);
			} else if (d[v] == c + w) {
				from[v].push_back(u);
			}
		}
	}

	queue<int> q;
	vector<bool> visited(g.size());
	vector<vector<bool>> need_removed(g.size(), vector<bool>(g.size()));

	visited[D] = true;
	q.push(D);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int u : from[v]) {
			need_removed[u][v] = true;
			if (!visited[u]) {
				visited[u] = true;
				q.push(u);
			}
		}
	}

	for (int u=0; u < g.size(); u++) {
		for (int i=0; i < g[u].size(); i++) {
			auto [v, w] = g[u][i];
			if (need_removed[u][v]) {
				g[u][i] = g[u].back();
				g[u].pop_back();
				i--;
			}
		}
	}

	return d[D] == INF? -1: d[D];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	while (true) {
		int V, E;
		cin >> V >> E;
		if (V == 0) break;

		int S, D;
		cin >> S >> D;

		vector<vector<pair<int, int>>> g(V);
		for (int i=0; i < E; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u].emplace_back(v, w);
		}

		dijkstra(g, S, D);
		cout << dijkstra(g, S, D) << endl;
	}

	return 0;
}
