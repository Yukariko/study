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

	DisjointSet(int N) : group(N + 1)
	{
		for (int i=1; i <= N; i++) {
			group[i] = i;
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
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> edges(M);
	for (auto& [u, v] : edges) {
		cin >> u >> v;
	}

	auto is_fully_connected = [&](const vector<bool>& closed) {
		DisjointSet djs(N);

		for (auto& [u, v] : edges) {
			if (!closed[u] && !closed[v]) {
				djs.merge(u, v);
			}
		}

		int g = 0;
		for (int i=1; i <= N; i++) {
			if (g && !closed[i] && g != djs.find(i)) {
				return false;
			}
			if (!g && !closed[i]) {
				g = djs.find(i);
			}
		}
		return true;
	};

	vector<bool> closed(N + 1);
	for (int i=0; i < N; i++) {
		int n;
		cin >> n;
		cout << (is_fully_connected(closed)? "YES": "NO") << endl;
		closed[n] = true;
	}

	return 0;
}
