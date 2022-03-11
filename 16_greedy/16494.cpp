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
	vector<string> a(N);
	for (auto& n : a) cin >> n;
	sort(a.begin(), a.end(), [](auto& p, auto& q) {
		if (p.size() == q.size()) {
			return q < p;
		}
		const char *sp = p.c_str();
		const char *sq = q.c_str();
		int np = p.size();
		int nq = q.size();
		while (1) {
			int minlen = min(np, nq);
			if (minlen == 0) return false;
			int cmp = strncmp(sp, sq, minlen);
			if (cmp > 0) return true;
			if (cmp == 0) {
				if (np > nq) {
					int len = min(np - minlen, nq);
					sp += minlen;
					np -= minlen;
				} else {
					int len = min(nq - minlen, np);
					sq += minlen;
					nq -= minlen;
				}
			} else {
				return false;
			}
		}
		return false;
	});

	if (a[0][0] == '0') {
		cout << 0 << endl;
		return 0;
	}
	for (auto& s : a) {
		cout << s;
	}
	cout << endl;
	return 0;
}


