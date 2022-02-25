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

vector<ll> sum;
ll C(int i, int j)
{
	return 1LL * (j - i) * (sum[j+1] - sum[i]);
}

vector<ll> d_cur, d_bef;

void compute(int l, int r, int optl, int optr)
{
	if (l > r) return;

	int mid = (l + r) / 2;
	pair<ll, int> best = {LLONG_MAX, -1};
	for (int k=optl, e=min(optr, mid); k <= e; k++) {
		best = min(best, { (k? d_bef[k-1] : 0) + C(k, mid), k });
	}

	d_cur[mid] = best.first;
	int opt = best.second;

	compute(l, mid - 1, optl, opt);
	compute(mid + 1, r, opt, optr);

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

	sum.resize(B+1);
	for (int i=1; i <= B; i++) sum[i] = sum[i-1] + d[i-1];

	d_bef.resize(B), d_cur.resize(B);
	for (int i=1; i < B; i++) {
		d_bef[i] = C(0, i);
	}

	for (int i=1; i < S; i++) {
		compute(0, B-1, 0, B-1);
		swap(d_bef, d_cur);
	}

	cout << d_bef[B-1] << endl;
	return 0;
}
