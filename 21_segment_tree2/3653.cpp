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

void build()
{
	for (int i = N-1; i > 0; i--) {
		t[i] = t[i * 2] + t[i * 2 + 1];
	}
}

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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;
		N = n + m;
		fill(&t[N], &t[N + n], 1);
		fill(&t[N + n], &t[N * 2], 0);
		build();

		vector<int> idx(n);
		for (int i=0; i < n; i++) {
			idx[i] = n - 1 - i;
		}

		int top = n;
		while (m--) {
			int pos;
			cin >> pos;

			cout << query(idx[pos - 1] + 1, N) << " ";
			update(idx[pos - 1], -1);
			idx[pos - 1] = top++;
			update(idx[pos - 1], 1);
		}
		cout << endl;
	}

	return 0;
}
