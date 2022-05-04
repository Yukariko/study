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
	int N, M;
	cin >> N >> M;

	vector<int> a(N);
	for (int& n : a) cin >> n;

	auto part = [&](int diff) {
		int mi = a[0];
		int ma = a[0];
		int cnt = 1;

		for (int n : a) {
			mi = min(mi, n);
			ma = max(ma, n);
			if (ma - mi > diff) {
				mi = ma = n;
				cnt++;
			}
		}
		return cnt <= M;
	};

	int lo = 0, hi = 10000;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (part(mid)) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout << lo << endl;

	return 0;
}
