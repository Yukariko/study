#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

vector<ll> sum;
vector<vector<ll>> d;

ll C(int i, int j)
{
	return 1LL * (j - i + 1) * (sum[j+1] - sum[i]);
}

void compute(int round, int l, int r, int optl, int optr)
{
	if (l > r) return;

	int mid = (l + r) / 2;
	pair<ll, int> best = {LLONG_MAX, -1};

	for (int k=optl, e=min(optr,mid); k <= e; k++) {
		best = min(best, { (k? d[round - 1][k - 1]: 0) + C(k, mid), k });
	}

	d[round][mid] = best.first;
	int opt = best.second;

	compute(round, l, mid - 1, optl, opt);
	compute(round, mid + 1, r, opt, optr);
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

	d.resize(G, vector<ll>(L));
	for (int i=0; i < L; i++) {
		d[0][i] = C(0, i);
	}
	for (int i=1; i < G; i++) {
		compute(i, 0, L-1, 0, L-1);
	}

	cout << d[G-1][L-1] << endl;

	return 0;
}
