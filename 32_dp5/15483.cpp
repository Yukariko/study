#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

string a, b;

int cache[1001][1001];

int solve(int ap, int bp)
{
	if (bp == b.length()) {
		return a.length() - ap;
	}
	if (ap == a.length()) {
		return b.length() - bp;
	}

	int& ret = cache[ap][bp];
	if (ret != -1) {
		return ret;
	}

	if (a[ap] == b[bp]) {
		ret = solve(ap + 1, bp + 1);
	} else {
		ret = 1 + min({solve(ap + 1, bp + 1), solve(ap + 1, bp), solve(ap, bp + 1)});
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> a >> b;

	memset(cache, -1, sizeof(cache));

	cout << solve(0, 0) << endl;

	return 0;
}
