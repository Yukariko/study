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
	int N, K;
	cin >> N >> K;

	vector<int> a(N);
	for (int& n : a) cin >> n;

	int lo = 0, hi = 0;
	int num = 0;
	while (hi < N && num < K) {
		num += a[hi] == 1;
		hi++;
	}

	if (num < K) {
		cout << -1 << endl;
		return 0;
	}

	int ans = hi - lo;
	while (hi < N) {
		num += a[hi] == 1;
		hi++;
		while (lo < hi && num >= K) {
			num -= a[lo] == 1;
			lo++;
		}
		ans = min(ans, hi - lo + 1);
	}

	cout << ans << endl;
	return 0;
}
