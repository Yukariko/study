#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

struct SegmentTree
{
	SegmentTree *L = nullptr,  *R = nullptr;

	int lo, hi;
	ll val = 0;

	SegmentTree(int lo, int hi) : lo(lo), hi(hi) {}
	
	SegmentTree(const vector<ll>& a)
	{
		lo = 0, hi = a.size() - 1;
		build(a, lo, hi);
	}

	ll build(const vector<ll>& a, int lo, int hi)
	{
		if (lo == hi) return val = a[lo];

		int mid = (lo + hi) / 2;
		L = new SegmentTree(lo, mid);
		R = new SegmentTree(mid + 1, hi);
		return val = L->build(a, lo, mid) + R->build(a, mid + 1, hi);
	}

	void update(int l, int r, ll v)
	{
		if (r < lo || hi < l) return;

		if (l <= lo && hi <= r) {
			if (lo == hi) val += v;
			else val = L->val + R->val;
			return;
		}

		L->update(l, r, v);
		R->update(l, r, v);
		val = L->val + R->val;
	}

	ll query(int l, int r)
	{
		if (r < lo || hi < l) return 0;
		if (l <= lo && hi <= r) return val;
		return L->query(l, r) + R->query(l, r);
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
		n = n - bef;
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
			st.update(L-1, L-1, V);
			st.update(R, R, -V);
		} else {
            cin >> L;
            cout << st.query(0, L-1) << endl;
        }
	}
    return 0;
}
