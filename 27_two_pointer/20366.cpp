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
	sort(a.begin(), a.end());

	int ans = a[3] + a[2] - a[1] - a[0];
	for (int i=0; i < N; i++) {
		for (int j=i+1; j < N; j++) {
			int tall = a[j] + a[i];
			int lo = 0, hi = N-1;
			while (lo < N) {
				if (lo == i || lo == j) {
					lo++;
					continue;
				}

				while (hi > lo) {
					if (hi == i || hi == j) {
						hi--;
						continue;
					}
					if (a[hi] + a[lo] <= tall) {
						ans = min(ans, tall - a[hi] - a[lo]);
						break;
					}
					hi--;
				}
				lo++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
