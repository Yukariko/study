#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

struct SegmentTree
{
	SegmentTree *L = nullptr, *R = nullptr;

	int lo, hi;
	ll val = 0;
	
	SegmentTree() {}
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

	static SegmentTree *dup(SegmentTree *st)
	{
		auto *nst = new SegmentTree;
		*nst = *st;
		return nst;
	}

	void update(int l, int r, ll v)
	{
		if (l <= lo && hi <= r) {
			if (lo == hi) val = v;
			else val = L->val + R->val;
			return;
		}

        if (l <= L->hi) { L = dup(L); L->update(l, r, v); }
        if (R->lo <= r) { R = dup(R); R->update(l, r, v); }
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
	for (ll& n : a)
		cin >> n;

	SegmentTree st(a);
	vector<SegmentTree *> pst(1, &st);

    int M;
    cin >> M;
	while (M--) {
		int O;
		cin >> O;

		if (O == 1) {
			int P, V;
			cin >> P >> V;
			pst.push_back(SegmentTree::dup(pst.back()));
			pst.back()->update(P-1, P-1, V);
		} else {
			int K, L, R;
            cin >> K >> L >> R;
            cout << pst[K]->query(L-1, R-1) << endl;
        }
	}
    return 0;
}
