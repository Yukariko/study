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

	sort(a.begin(), a.end());

	int lo = 0, hi = 0;
	while (hi < N && a[hi] - a[lo] < M) {
		hi++;
	}

	int ans = a[hi] - a[lo];

	while (hi < N) {
		while (lo < hi && a[hi] - a[lo + 1] >= M) {
			lo++;
		}
		ans = min(ans, a[hi] - a[lo]);
		hi++;
	}

	cout << ans << endl;

	return 0;
}
