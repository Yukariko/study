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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> D;

	T.resize(N), V.resize(N);

	for (int& n : T) cin >> n;
	for (int& n : V) cin >> n;

	ll ans = 0;
	int opt = 0;
	for (int i=0; i < N; i++) {
		pair<ll, int> best = {0, -1};
		for (int j=max(opt, i - D); j <= i; j++) {
			best = max(best, { C(j, i), j });
		}
		ans = max(ans, best.first);
		opt = best.second;
	}

	cout << ans << endl;

	return 0;
}
