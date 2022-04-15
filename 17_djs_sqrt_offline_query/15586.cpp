#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

struct DisjointSet
{
	vector<int> group;
	vector<int> size;

	DisjointSet(int N) : group(N + 1), size(N + 1)
	{
		for (int i=1; i <= N; i++) {
			group[i] = i;
			size[i] = 1;
		}
	}

	int find(int u)
	{
		if (u == group[u]) {
			return u;
		}
		return group[u] = find(group[u]);
	}

	void merge(int u, int v)
	{
		u = find(u);
		v = find(v);

		if (u != v) {
			group[u] = v;
			size[v] += size[u];
		}
	}
};


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, Q;
	cin >> N >> Q;
	
	vector<tuple<int, int, int>> edges(N - 1);
	for (auto& [u, v, w] : edges) {
		cin >> u >> v >> w;
	}

	sort(edges.begin(), edges.end(), [](auto& p, auto& q) {
		return get<2>(p) > get<2>(q);
	});

	vector<tuple<int, int, int>> queries(Q);
	for (int idx = 0; auto& [k, v, i] : queries) {
		cin >> k >> v;
		i = idx++;
	}

	sort(queries.begin(), queries.end(), [](auto& p, auto& q) {
		return get<0>(p) > get<0>(q);
	});

	DisjointSet djs(N);
	vector<int> ans(Q);
	int lo = 0;

	for (auto& [u, v, w] : edges) {
		while (lo < Q) {
			auto& [k, v, i] = queries[lo];
			if (w < k) {
				ans[i] = djs.size[djs.find(v)] - 1;
				lo++;
			} else {
				break;
			}
		}
		djs.merge(u, v);
	}

	while (lo < Q) {
		auto& [k, v, i] = queries[lo];
		ans[i] = djs.size[djs.find(v)] - 1;
		lo++;
	}

	for (int n : ans) {
		cout << n << endl;
	}
	return 0;
}
