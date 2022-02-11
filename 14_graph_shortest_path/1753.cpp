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
	int V, E;
	cin >> V >> E;

	int K;
	cin >> K;

	vector<vector<pair<int, int>>> g(V + 1);
	for (int i=0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
	}

	const int INF = 1e9;
	vector<int> d(V + 1, INF);
	priority_queue<pair<int, int>> pq;
	d[K] = 0;
	pq.emplace(0, K);

	while (!pq.empty()) {
		auto [c, u] = pq.top();
		pq.pop();
		c = -c;

		if (d[u] < c) continue;

		for (auto [v, w] : g[u]) {
			if (d[v] > c + w) {
				d[v] = c + w;
				pq.emplace(-d[v], v);
			}
		}
	}

	for (int i=1; i <= V; i++) {
		if (d[i] == INF) {
			cout << "INF" << endl;
		} else {
			cout << d[i] << endl;
		}
	}

	return 0;
}
