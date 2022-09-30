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
    for (int T=1; cin >> N >> M, N != 0; T++) {
        DisjointSet djs(N);
        vector<int> cycle_node;
        for (int i=0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            if (!djs.merge(u, v)) {
                cycle_node.push_back(u);
            }
        }

        int ans = djs.group_num();

        vector<bool> cycle(N + 1);
        for (int n : cycle_node) {
            n = djs.find(n);
            if (!cycle[n]) {
                cycle[n] = true;
                ans--;
            }
        }
        
        if (ans == 0) {
            cout << "Case " << T << ": No trees." << endl;
        } else if (ans == 1) {
            cout << "Case " << T << ": There is one tree." << endl;
        } else {
            cout << "Case " << T << ": A forest of " << ans << " trees." << endl;
        }
    }
	return 0;
}
