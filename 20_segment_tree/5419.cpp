#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int MAX_N = 75000;

int N;
int t[MAX_N * 2];

void update(int pos, int val)
{
	for (t[pos += N] += val; pos > 1; pos /= 2) {
		t[pos / 2] = t[pos] + t[pos ^ 1];
	}
}

int query(int l, int r)
{
	int sum = 0;
	for (l += N, r += N; l < r; l /= 2, r /= 2) {
		if (l & 1) sum += t[l++];
		if (r & 1) sum += t[--r];
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T;
	cin >> T;

	while (T--) {
		cin >> N;

		memset(t, 0, sizeof(t));

		vector<pair<int, int>> a(N);
		vector<int> ys;
		for (auto& [x, y] : a) {
			cin >> x >> y;
			ys.push_back(y);
		}

		sort(a.begin(), a.end(), [](auto p, auto q) {
			if (p.first != q.first) {
				return p.first < q.first;
			}
			return p.second > q.second;
		});
		sort(ys.begin(), ys.end());
		ys.erase(unique(ys.begin(), ys.end()), ys.end());

		ll ans = 0;
		for (auto& [x, y] : a) {
			int idx = lower_bound(ys.begin(), ys.end(), y) - ys.begin();
			ans += query(idx, ys.size());
			update(idx, 1);
		}

		cout << ans << endl;
	}

	return 0;
}


