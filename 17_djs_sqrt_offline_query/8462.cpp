#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, T;
	cin >> N >> T;

	vector<int> a(N);
	for (int& n : a) {
		cin >> n;
	}

	vector<tuple<int, int, int>> queries(T);
	for (int idx=0; auto& [l, r, i] : queries) {
		cin >> l >> r;
		l--;
		i = idx++;
	}

	int sz = sqrt(N);
	sort(queries.begin(), queries.end(), [&](auto& p, auto& q) {
		int g1 = get<1>(p) / sz, g2 = get<1>(q) / sz;
		if (g1 != g2) {
			return g1 < g2;
		}
		return get<0>(p) < get<0>(q);
	});

	vector<int> used(1000001);
	ll res = 0;

	auto add = [&](int n) {
		used[n]++;
		res += 1LL * n * (2 * used[n] - 1);
	};

	auto sub = [&](int n) {
		res -= 1LL * n * (2 * used[n] - 1);
		used[n]--;
	};

	vector<ll> ans(T);
	int lo = 0, hi = 0;
	for (auto& [l, r, i] : queries) {
		while (hi < r) add(a[hi++]);
		while (hi > r) sub(a[--hi]);
		while (lo < l) sub(a[lo++]);
		while (lo > l) add(a[--lo]);
		ans[i] = res;
	}

	for (ll n : ans) {
		cout << n << endl;
	}
	return 0;
}
