#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

struct SegmentTree
{
	int N;
	vector<ll> t, d;

	int l, r;
	ll v;

	SegmentTree(int N) : N(N), t(4 * N), d(4 * N) {}
	
	SegmentTree(const vector<ll>& a) : N(a.size()), t(4 * N), d(4 * N)
	{
		build(a, 1, 0, N-1);
	}

	ll build(const vector<ll>& a, int idx, int lo, int hi)
	{
		if (lo == hi) return t[idx] = a[lo];

		int mid = (lo + hi) / 2;
		return t[idx] = build(a, idx * 2, lo, mid) + build(a, idx * 2 + 1, mid + 1, hi);
	}

	void apply(int idx, int lo, int hi)
	{
		if (d[idx] == 0) return;
		if (lo != hi) {
			d[idx * 2] += d[idx];
			d[idx * 2 + 1] += d[idx];
		}
		t[idx] += d[idx] * (hi - lo + 1);
		d[idx] = 0;
	}

	void update(int idx, int lo, int hi)
	{
		apply(idx, lo, hi);
		if (r < lo || hi < l) return;

		if (l <= lo && hi <= r) {
			d[idx] = v;
			apply(idx, lo, hi);
			return;
		}

		int mid = (lo + hi) / 2;
		update(idx * 2, lo, mid);
		update(idx * 2 + 1, mid + 1, hi);
		t[idx] = t[idx * 2] + t[idx * 2 + 1];
	}

	ll query(int idx, int lo, int hi)
	{
		apply(idx, lo, hi);
		if (r < lo || hi < l) return 0;
		if (l <= lo && hi <= r) return t[idx];

		int mid = (lo + hi) / 2;
		return query(idx * 2, lo, mid) + query(idx * 2 + 1, mid + 1, hi);
	}


	void update(int _l, int _r, ll val)
	{
		l = _l, r = _r, v = val;
		update(1, 0, N-1);
	}

	ll query(int _l, int _r)
	{
		l = _l, r = _r;
		return query(1, 0, N-1);
	}
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;
	
	vector<ll> a(N);
	for (ll& n : a)
		cin >> n;

	SegmentTree st(a);
	
	M += K;
	while (M--) {
		int O, L, R;
		cin >> O >> L >> R;

		if (O == 1) {
			ll V;
			cin >> V;
			st.update(L-1, R-1, V);
		}
		else cout << st.query(L-1, R-1) << endl;
	}
    return 0;
}
