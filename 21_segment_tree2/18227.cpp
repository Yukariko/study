#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int MAX_N = 200000;

int N;
int t[MAX_N * 2];

void update(int pos, int val)
{
	for (t[pos += N] += val; pos > 1; pos /= 2) {
		t[pos / 2] = t[pos] + t[pos ^ 1];
	}
}

int query(int l, int r)
{
	int sum = 0;
	for (l += N, r += N; l < r; l /= 2, r /= 2) {
		if (l & 1) sum += t[l++];
		if (r & 1) sum += t[--r];
	}
	return sum;
}

int V;
vector<int> g[200001];
int S[200001];
int E[200001];
int depth[200001];
int idx;

void dfs(int u, int p)
{
	S[u] = idx++;
	depth[u] = depth[p] + 1;

	for (int v : g[u]) {
		if (v == p) continue;
		dfs(v, u);
	}

	E[u] = idx;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int C;
	cin >> V >> C;

	for (int i=1; i < V; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(C, 0);

	N = idx;

	int Q;
	cin >> Q;

	while (Q--) {
		int O, A;
		cin >> O >> A;

		if (O == 1) {
			update(S[A], 1);
		} else {
			cout << 1LL * query(S[A], E[A]) * depth[A] << endl;
		}
	}

	return 0;
}
