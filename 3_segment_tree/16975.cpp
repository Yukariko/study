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
	vector<ll> t;

	int l, r;
	ll v;

	SegmentTree(int N) : N(N), t(4 * N) {}
	
	SegmentTree(const vector<ll>& a) : N(a.size()), t(4 * N)
	{
		build(a, 1, 0, N-1);
	}

	ll build(const vector<ll>& a, int idx, int lo, int hi)
	{
		if (lo == hi) return t[idx] = a[lo];

		int mid = (lo + hi) / 2;
		return t[idx] = build(a, idx * 2, lo, mid) + build(a, idx * 2 + 1, mid + 1, hi);
	}

	void update(int idx, int lo, int hi)
	{
		if (r < lo || hi < l) return;

		if (l <= lo && hi <= r) {
			if (lo == hi) t[idx] += v;
			else t[idx] = t[idx * 2] + t[idx * 2 + 1];
			return;
		}

		int mid = (lo + hi) / 2;
		update(idx * 2, lo, mid);
		update(idx * 2 + 1, mid + 1, hi);
		t[idx] = t[idx * 2] + t[idx * 2 + 1];
	}

	ll query(int idx, int lo, int hi)
	{
		if (r < lo || hi < l) return 0;
		if (l <= lo && hi <= r) return t[idx];

		int mid = (lo + hi) / 2;
		return query(idx * 2, lo, mid) + query(idx * 2 + 1, mid + 1, hi);
	}


	void update(int pos, ll val)
	{
		l = r = pos, v = val;
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

	int N;
	cin >> N;

	vector<ll> a(N);
	ll bef = 0;
	for (ll& n : a) {
		cin >> n;
		ll t = n;
		n -= bef;
		bef = t;
	}

	SegmentTree st(a);

    int M;
    cin >> M;
	while (M--) {
		int O, L, R;
		cin >> O;

		if (O == 1) {
			ll V;
			cin >> L >> R >> V;
			st.update(L-1, V);
			st.update(R, -V);
		} else {
            cin >> L;
            cout << st.query(0, L-1) << endl;
        }
	}
    return 0;
}
