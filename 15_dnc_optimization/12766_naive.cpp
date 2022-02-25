#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

void dijkstra(const vector<vector<pair<int, int>>>& g, int s, vector<int>& d)
{
	const int INF = 1e9;
	int N = g.size();
	d.resize(N, INF);

	priority_queue<pair<int, int>> pq;
	d[s] = 0;
	pq.emplace(0, s);

	while (!pq.empty()) {
		auto [c, u] = pq.top();
		c = -c;
		pq.pop();

		if (d[u] < c) continue;

		for (auto& [v, w] : g[u]) {
			if (d[v] > c + w) {
				d[v] = c + w;
				pq.emplace(-d[v], v);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int N, B, S, R;
	cin >> N >> B >> S >> R;

	vector<vector<pair<int, int>>> g(N), rg(N);
	for (int i=0; i < R; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		g[u].emplace_back(v, w);
		rg[v].emplace_back(u, w);
	}

	vector<int> d, rd;
	dijkstra(g, B, d);
	dijkstra(rg, B, rd);

	for (int i=0; i < B; i++) d[i] += rd[i];

	sort(d.begin(), d.begin() + B);

	vector<int> sum(B + 1);
	for (int i=1; i <= B; i++) sum[i] = sum[i-1] + d[i-1];

	auto C = [&](int i, int j) {
		return 1LL * (j - i) * (sum[j+1] - sum[i]);
	};

	vector<ll> d_cur(B), d_bef(B);
	for (int i=1; i < B; i++) {
		d_bef[i] = C(0, i);
	}

	for (int i=1; i < S; i++) {
		for (int j=0; j < B; j++) {
			d_cur[j] = d_bef[j];
			for (int k=1; k <= j; k++) {
				d_cur[j] = min(d_cur[j], C(k, j) + d_bef[k - 1]);
			}
		}
		swap(d_bef, d_cur);
	}

	cout << d_bef[B-1] << endl;
	return 0;
}
