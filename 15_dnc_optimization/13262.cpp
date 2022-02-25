#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

vector<int> a;
vector<ll> d_cur, d_bef;

void compute(int l, int r, int optl, int optr)
{
	if (l > r) return;

	int mid = (l + r) / 2;
	pair<ll, int> best = {0, -1};

	ll sum = 0;
	for (int i=optr; i <= mid; i++) sum |= a[i];
	for (int k=optl, e=min(optr, mid); k <= e; e--) {
		sum |= a[e];
		best = max(best, { (e? d_bef[e-1] : 0) + sum, e });
	}

	d_cur[mid] = best.first;
	int opt = best.second;

	compute(l, mid - 1, optl, opt);
	compute(mid + 1, r, opt, optr);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, K;
	cin >> N >> K;

	a.resize(N);
	for (int& n : a) cin >> n;

	d_cur.resize(N), d_bef.resize(N);

	d_bef[0] = a[0];
	for (int i=1; i < N; i++) {
		d_bef[i] = d_bef[i-1] | a[i];
	}

	for (int i=1; i < K; i++) {
		compute(0, N-1, 0, N-1);
		swap(d_bef, d_cur);
	}

	cout << d_bef[N-1] << endl;

	return 0;
}
