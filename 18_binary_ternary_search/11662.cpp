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
	vector<pair<int, int>> a(4);
	for (auto& [x, y] : a) cin >> x >> y;

	auto calc = [](int s, int e, double rat) {
		return s + (e - s) * rat;
	};

	auto dist = [&](double rat) {
		double ax = calc(a[0].first, a[1].first, rat);
		double ay = calc(a[0].second, a[1].second, rat);
		double bx = calc(a[2].first, a[3].first, rat);
		double by = calc(a[2].second, a[3].second, rat);

		return sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
	};

	double lo = 0.0, hi = 1.0;
#if 1
	while (abs(lo - hi) >= 1e-9) {
		double mid = (lo * 2 + hi) / 3;
		double mid2 = (lo + hi * 2) / 3;
		if (dist(mid) >= dist(mid2)) {
			lo = mid;
		} else {
			hi = mid2;
		}
	}
#else
	for (int d = 0; d < 100; d++) {
		double mid = (lo * 2 + hi) / 3;
		double mid2 = (lo + hi * 2) / 3;
		if (dist(mid) >= dist(mid2)) {
			lo = mid;
		} else {
			hi = mid2;
		}
	}
#endif
	cout.precision(9);
	cout << fixed << dist(lo) << endl;

	return 0;
}
