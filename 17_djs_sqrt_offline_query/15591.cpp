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
	int N, Q;
	cin >> N >> Q;

	vector<vector<pair<int, int>>> g(N + 1);
	for (int i=1; i < N; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}

	auto suggest_count = [&](int K, int V) {
		vector<bool> visited(N + 1);
		queue<int> q;
		q.push(V);
		visited[V] = true;

		int cnt = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (auto& [v, w] : g[u]) {
				if (w < K || visited[v]) continue;
				visited[v] = true;
				q.push(v);
				cnt++;
			}
		}
		return cnt;
	};

	while (Q--) {
		int K, V;
		cin >> K >> V;
		cout << suggest_count(K, V) << endl;
	}
	return 0;
}
