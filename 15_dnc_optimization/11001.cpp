#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int N, D;
vector<int> T, V;

ll C(int i, int j)
{
	return 1LL * (j - i) * T[j] + V[i];
}

ll ans;

void compute(int l, int r, int optl, int optr)
{
	if (l > r) return;

	int mid = (l + r) / 2;
	pair<ll, int> best = {0, -1};

	for (int k=max(optl, mid - D), e=min(optr, mid); k <= e; k++) {
		best = max(best, { C(k, mid), k});
	}

	ans = max(ans, best.first);
	int opt = best.second;

	compute(l, mid - 1, optl, opt);
	compute(mid + 1, r, opt, optr);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> D;

	T.resize(N), V.resize(N);

	for (int& n : T) cin >> n;
	for (int& n : V) cin >> n;

	compute(0, N-1, 0, N-1);

	cout << ans << endl;

	return 0;
}
