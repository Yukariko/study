#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

struct DisjointSet {
	vector<int> group;
	DisjointSet(int N)
	{
		group.resize(N + 1);
		for (int i=1; i <= N; i++)
			group[i] = i;
	}

	int find(int n)
	{
		if (group[n] == n)
			return n;
		return group[n] = find(group[n]);
	}

	bool merge(int p, int q)
	{
		p = find(p);
		q = find(q);
		if (p != q) {
			group[p] = q;
            return true;
        }
        return false;
	}
};

int mst(int N, vector<tuple<int, int, int>>& edges)
{
    sort(edges.begin(), edges.end());

    DisjointSet djs(N);

    int ans = 0;
    for (auto& [w, u, v] : edges) {
        if (djs.merge(u, v))
            ans += w;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, K;
    while (cin >> N >> M >> K, N) {
        vector<tuple<int, int, int>> edges(M);
        for (int i=0; i < M; i++) {
            char color;
            int u, v;
            cin >> color >> u >> v;

            edges[i] = { color == 'B'? 1: 0, u, v };
        }

        int lo = mst(N, edges);

        for (auto& [w, _, __] : edges) {
            w = !w;
        }

        int hi = N - mst(N, edges) - 1;

        if (lo <= K && K <= hi)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
