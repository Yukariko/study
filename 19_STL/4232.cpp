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

	for (int N; cin >> N, N != 0; ) {
		int max_eq = 0;
		map<vector<int>, int> cnt;
		for (int i=0; i < N; i++) {
			vector<int> a(5);
			for (int& n : a) cin >> n;
			sort(a.begin(), a.end());
			max_eq = max(max_eq, ++cnt[move(a)]);
		}

		int ans = 0;
		for (auto& [vec, n] : cnt) {
			if (n == max_eq) {
				ans += n;
			}
		}

		cout << ans << endl;
	}

	return 0;
}
