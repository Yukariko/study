#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 200001;

struct SegmentTree
{
	int N;
	vector<ll> t;

	SegmentTree(int N) : N(N), t(N * 2) {}

	void update(int pos, ll val)
	{
		for (t[pos += N] += val; pos > 1; pos /= 2) {
			t[pos / 2] = t[pos] + t[pos ^ 1];
		}
	}

	ll query(int l, int r)
	{
		ll sum = 0;
		for (l += N, r += N; l < r; l /= 2, r /= 2) {
			if (l & 1) sum += t[l++];
			if (r & 1) sum += t[--r];
		}
		return sum;
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;

	SegmentTree sum(MAX_N), cnt(MAX_N);

	int ans = 1;

	int n;
	cin >> n;
	cnt.update(n, 1);
	sum.update(n, n);

	for (int i=1; i < N; i++) {
		int n;
		cin >> n;

		ll cost = n * cnt.query(0, n) - sum.query(0, n) +
				  sum.query(n + 1, MAX_N) - n * cnt.query(n + 1, MAX_N);
		cost %= MOD;

		ans = (ans * cost) % MOD;
		cnt.update(n, 1);
		sum.update(n, n);
	}

	cout << ans << endl;

	return 0;
}
