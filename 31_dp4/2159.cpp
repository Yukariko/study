#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int dy[] = {0, 0, 0, 1, -1};
const int dx[] = {0, 1, -1, 0, 0};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N;
	cin >> N;
	N++;

	vector<pair<int, int>> a(N);
	for (auto& [x, y] : a) {
		cin >> x >> y;
	}

	auto calc_dist = [](auto& p1, auto& p2) {
		return abs(p1.first - p2.first) + abs(p1.second - p2.second);
	};

	auto move1 = [](auto& p, int dir)->pair<ll, ll> {
		return make_pair(p.first + dx[dir], p.second + dy[dir]);
	};

	vector<vector<ll>> d(N, vector<ll>(5, (ll)1e18));
	for (int dir=0; dir < 5; dir++) {
		auto p2 = move1(a[1], dir);
		int dist = calc_dist(a[0], p2);
		d[1][dir] = dist;
	}

	for (int i=2; i < N; i++) {
		for (int dir1=0; dir1 < 5; dir1++) {
			auto p1 = move1(a[i-1], dir1);
			for (int dir2=0; dir2 < 5; dir2++) {
				auto p2 = move1(a[i], dir2);
				ll dist = calc_dist(p1, p2);
				d[i][dir2] = min(d[i][dir2], d[i-1][dir1] + dist);
			}
		}
	}

	ll ans = *min_element(d[N-1].begin(), d[N-1].end());
	cout << ans << endl;

	return 0;
}
