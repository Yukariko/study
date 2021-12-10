#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int MOD = 1e9 + 7;

template <int BASE = 29>
struct Hash
{
	vector<int> h, p;
	Hash (const string& s) : h(s.size()), p(s.size())
	{
		int N = s.size();
		h[0] = s[0];
		p[0] = 1;
		for (int i=1; i < N; i++) {
			h[i] = (1LL * h[i-1] * BASE + s[i]) % MOD;
			p[i] = 1LL * p[i-1] * BASE % MOD;
		}
	}

	int value(int idx, int len)
	{
		if (idx == 0)
			return h[len - 1];
		return (h[idx + len - 1] - 1LL * h[idx - 1] * p[len] % MOD + MOD) % MOD;
	}

};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    string s;
    cin >> N >> s;

    Hash hash(s);
    vector<pair<int, int>> oc;

    for (int i=1; i < N; i++) {
        int lo = i + 1, hi = min(i * 2, N);
        bool found = false;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int len = mid - i;
            if (hash.value(0, len) == hash.value(i, len)) {
                lo = mid + 1;
                found = true;
            } else {
                hi = mid - 1;
            }
        }
        if (found) {
            oc.emplace_back(i, i);
            oc.emplace_back(lo - 1, -i);
        }
    }

    sort(oc.begin(), oc.end());

    ll ans = 0;
	int lo=0;
	set<int> candidates;
	for (int i=0; i < N; i++) {
		while (lo < oc.size()) {
			auto [j, n] = oc[lo];
			if (j > i) break;
			if (n < 0) candidates.erase(-n);
			else candidates.insert(n);
			lo++;
		}
		if (!candidates.empty()) ans += *prev(candidates.end());
	}
    cout << ans << endl;
    return 0;
}
