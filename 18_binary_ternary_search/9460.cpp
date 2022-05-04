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
	int T;
	cin >> T;

	while (T--) {
		int N, K;
		cin >> N >> K;

		vector<pair<int, int>> a(N);
		for (auto& [x, y] : a) {
			cin >> x >> y;
			y *= 2;
		}
		sort(a.begin(), a.end());

		auto inplace = [&](int cost) {
			ll lo = 1LL * a[0].second - cost;
			ll hi = 1LL * a[0].second + cost;

			int cnt = 1;
			for (auto& [x, y] : a) {
				ll cur_lo = 1LL * y - cost;
				ll cur_hi = 1LL * y + cost;
				if (hi < cur_lo || cur_hi < lo) {
					cnt++;
					lo = cur_lo;
					hi = cur_hi;
				} else {
					lo = max(lo, cur_lo);
					hi = min(hi, cur_hi);
				}
			}
			return cnt <= K;
		};

		int lo = 0, hi = 2e9;
		while (lo <= hi) {
			int mid = 1LL * (lo + hi) / 2;

			if (inplace(mid)) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}

		cout << lo / 2;
		if (lo % 2) {
			cout << ".5" << endl;
		} else {
			cout << ".0" << endl;
		}
	}

	return 0;
}
