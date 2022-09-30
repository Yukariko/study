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

	void merge(int p, int q)
	{
		p = find(p);
		q = find(q);
		if (p != q)
			group[p] = q;
	}

	int group_num()
	{
		vector<bool> check(group.size());
		int ans = 0;
		for (int i=1; i < group.size(); i++)
			if (!check[find(i)])
				check[find(i)] = true, ans++;
		return ans;
	}
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M;
    cin >> N >> M;

	DisjointSet djs(N);

	vector<vector<int>> enemy(N+1);
	vector<bool> visit(N+1);

	while (M--) {
		char c;
		int p, q;
        cin >> c >> p >> q;

		if (c == 'F') {
			djs.merge(p, q);
        } else {
			enemy[p].push_back(q);
			enemy[q].push_back(p);
			visit[p] = visit[q] = true;
		}
	}

	for (int i=1; i <= N; i++) {
		if (!visit[i])
			continue;

		for (size_t j=0; j < enemy[i].size(); j++)
			for (size_t k=j+1; k < enemy[i].size(); k++)
				djs.merge(enemy[i][j], enemy[i][k]);
	}

    cout << djs.group_num() << endl;
	return 0;
}
