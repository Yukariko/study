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
	int N, M;
	cin >> N >> M;

	vector<vector<int>> g(N + 1);
	for (int i=0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}


	vector<int> close_list(N);
	vector<bool> closed(N + 1);
	for (int& n : close_list) {
		cin >> n;
		closed[n] = true;
	}


	DisjointSet djs(N);
	vector<bool> fully_connected(N);

	closed[close_list[N-1]] = false;
	fully_connected[N-1] = true;

	for (int i=N-2; i >= 0; i--) {
		int u = close_list[i];
		closed[u] = false;

		for (int v : g[u]) {
			if (!closed[v]) {
				djs.merge(u, v);
			}
		}

		if (djs.size[djs.find(close_list[N - 1])] == N - i) {
			fully_connected[i] = true;
		}
	}

	for (int i=0; i < N; i++) {
		if (fully_connected[i]) {
			 cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
