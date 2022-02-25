#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

vector<ll> sum;
vector<ll> d_cur, d_bef;

ll C(int i, int j)
{
	return 1LL * (j - i + 1) * (sum[j+1] - sum[i]);
}

void compute(int l, int r, int optl, int optr)
{
	if (l > r) return;

	int mid = (l + r) / 2;
	pair<ll, int> best = {LLONG_MAX, -1};

	for (int k=optl, e=min(optr,mid); k <= e; k++) {
		best = min(best, { (k? d_bef[k - 1]: 0) + C(k, mid), k });
	}

	d_cur[mid] = best.first;
	int opt = best.second;

	compute(l, mid - 1, optl, opt);
	compute(mid + 1, r, opt, optr);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int L, G;
	cin >> L >> G;

	vector<int> a(L);
	for (int& n : a) cin >> n;

	sum.resize(L+1);
	for (int i=1; i <= L; i++) sum[i] = sum[i-1] + a[i-1];

	d_cur.resize(L); d_bef.resize(L);
	for (int i=0; i < L; i++) {
		d_bef[i] = C(0, i);
	}
	for (int i=1; i < G; i++) {
		compute(0, L-1, 0, L-1);
		swap(d_bef, d_cur);
	}

	cout << d_bef[L-1] << endl;

	return 0;
}
