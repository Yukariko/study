#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

struct DisjointSet {
	vector<int> group;
	vector<int> count;
	DisjointSet(int N)
	{
		group.resize(N);
		for (int i=0; i < N; i++)
			group[i] = i;

		count.resize(N, 1);
	}

	int find(int n)
	{
		if (group[n] == n)
			return n;
		return group[n] = find(group[n]);
	}

	int merge(int p, int q)
	{
		p = find(p);
		q = find(q);
		if(p != q) {
			group[p] = q;
			count[q] += count[p];
		}
		return count[q];
	}

	int group_num()
	{
		vector<bool> check(group.size(), false);
		int ans = 0;
		for (int i=0; i < group.size(); i++)
			if (check[find(i)] == false)
				check[find(i)] = true, ans++;
		return ans;
	}
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        DisjointSet djs(2 * N);

		int idx = 0;
		map<string, int> check;

		for (int i=0; i < N; i++) {
			char a[21], b[21];
            cin >> a >> b;

			int ai, bi;
			if (check.count(a) == 0)
				check[a] = idx++;
			ai = check[a];

			if (check.count(b) == 0)
				check[b] = idx++;
			bi = check[b];

			cout << djs.merge(ai, bi) << endl;
		}
    }
    return 0;
}
