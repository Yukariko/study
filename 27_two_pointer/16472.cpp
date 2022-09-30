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

	string s;
	cin >> s;

	vector<int> check(26);

	int len = s.size();
	int cnt = 0;

	auto add = [&](int i) {
		int idx = s[i] - 'a';
		if (!check[idx]) {
			cnt++;
		}
		check[idx]++;
	};

	auto del = [&](int i) {
		int idx = s[i] - 'a';
		check[idx]--;
		if (!check[idx]) {
			cnt--;
		}
	};

	int lo = 0, hi = 0;
	while (hi < len && cnt <= N) {
		add(hi);
		if (cnt > N) break;
		hi++;
	}

	int ans = hi;

	while (hi < len) {
		while (lo < hi && cnt > N) {
			del(lo);
			lo++;
		}
		ans = max(ans, hi - lo + 1);
		hi++;
		if (hi < len) {
			add(hi);
		}
	}

	cout << ans << endl;

	return 0;
}
