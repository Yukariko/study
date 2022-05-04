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
	int N;
	cin >> N;

	vector<int> a(N);
	for (int& n : a) cin >> n;

	auto dist = [&](int diff) {
		ll sum = 0;
		ll pos = 0;
		for (int n : a) {
			sum += abs(pos - n);
			pos += diff;
		}

		return sum;
	};

	int lo = 1, hi = 1e9;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		int mid2 = mid + 1;

		if (dist(mid) >= dist(mid2)) {
			lo = mid2;
		} else {
			hi = mid;
		}
	}

	cout << dist(lo) << endl;

	return 0;
}
