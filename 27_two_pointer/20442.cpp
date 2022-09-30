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
	string s;
	cin >> s;

	int N = s.size();
	int lo = 0, hi = N-1;
	int cnt_r = 0, cnt_k = 0;
	for (int i=lo; i <= hi; i++) {
		if (s[i] == 'R') {
			cnt_r++;
		}
	}

	int ans = cnt_r;

	while (lo < hi && cnt_r > 0) {
		if (s[lo] == 'R') {
			lo++;
			cnt_r--;
			continue;
		}
		lo++;

		while (lo < hi && s[hi] == 'R') {
			cnt_r--;
			hi--;
		}
		if (lo < hi && cnt_r > 0) {
			cnt_k++;
			ans = max(ans, cnt_r + cnt_k * 2);
			hi--;
		}
	}

	cout << ans << endl;
	return 0;
}
