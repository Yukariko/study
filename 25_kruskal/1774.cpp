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

double dist(const pair<int, int>& p, const pair<int, int>& q)
{
	return sqrt(1. * (p.first - q.first) * (p.first - q.first) + 1. * (p.second - q.second) * (p.second - q.second));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> a(N);
    for (auto& [x, y] : a) {
        cin >> x >> y;
    }

	vector<tuple<double, int, int>> edges;
	for (int i=0; i < N; i++)
		for (int j=0; j < N; j++)
			edges.emplace_back(dist(a[i], a[j]), i + 1, j + 1);

	sort(edges.begin(), edges.end());

    DisjointSet djs(N);
	for (int i=0; i < M; i++)
	{
		int p, q;
        cin >> p >> q;
		djs.merge(p, q);
	}

	double ans = 0;
    for (auto& [d, u, v] : edges) {
		if (djs.merge(u, v))
            ans += d;
    }

    cout << fixed;
    cout.precision(2);
    cout << ans << endl;
	return 0;
}
