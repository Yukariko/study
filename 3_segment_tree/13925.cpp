#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int MOD = 1e9 + 7;

struct SegmentTree
{
	int N;
	vector<int> t;
	vector<pair<int, int>> d;

	int l, r;
	int a, b;

	SegmentTree(int N) : N(N), t(4 * N), d(4 * N, {1, 0}) {}

	SegmentTree(const vector<int>& a) : SegmentTree(a.size())
	{
		build(a, 1, 0, N-1);
	}

	int build(const vector<int>& a, int idx, int lo, int hi)
	{
		if (lo == hi) return t[idx] = a[lo];

		int mid = (lo + hi) / 2;
		return t[idx] = (build(a, idx * 2, lo, mid) + build(a, idx * 2 + 1, mid + 1, hi)) % MOD;
	}

	void apply(int idx, int lo, int hi)
	{
		auto [a1, b1] = d[idx];
		if (a == 1 && b == 0) return;
		if (lo != hi) {
			for (int i=0; i < 2; i++) {
				auto& [a2, b2] = d[idx * 2 + i];
				a2 = 1LL * a2 * a1 % MOD;
				b2 = (1LL * b2 * a1 + b1) % MOD;
			}
		}
		t[idx] = (1LL * a1 * t[idx] % MOD + 1LL * b1 * (hi - lo + 1) % MOD) % MOD;
		d[idx] = {1, 0};
	}

	void update(int idx, int lo, int hi)
	{
		apply(idx, lo, hi);
		if (r < lo || hi < l) return;

		if (l <= lo && hi <= r) {
			d[idx] = {a, b};
			apply(idx, lo, hi);
			return;
		}

		int mid = (lo + hi) / 2;
		update(idx * 2, lo, mid);
		update(idx * 2 + 1, mid + 1, hi);
		t[idx] = (t[idx * 2] + t[idx * 2 + 1]) % MOD;
	}

	int query(int idx, int lo, int hi)
	{
		apply(idx, lo, hi);
		if (r < lo || hi < l) return 0;
		if (l <= lo && hi <= r) return t[idx];

		int mid = (lo + hi) / 2;
		return (query(idx * 2, lo, mid) + query(idx * 2 + 1, mid + 1, hi)) % MOD;
	}


	void update(int _l, int _r, int _a, int _b)
	{
		l = _l, r = _r;
		a = _a, b = _b;
		update(1, 0, N-1);
	}

	int query(int _l, int _r)
	{
		l = _l, r = _r;
		return query(1, 0, N-1);
	}
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> a(N);
	for (int& n : a)
		cin >> n;

	SegmentTree st(a);

    int M;
    cin >> M;
	while (M--) {
		int O, L, R, V;
		cin >> O >> L >> R;
		L--, R--;
		if (O != 4) cin >> V;

		switch (O) {
		case 1: st.update(L, R, 1, V); break;
		case 2: st.update(L, R, V, 0); break;
		case 3: st.update(L, R, 0, V); break;
		case 4: cout << st.query(L, R) << endl; break;
		}
	}
    return 0;
}

