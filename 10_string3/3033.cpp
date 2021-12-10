#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int MOD = 1e9 + 7;

template <int BASE = 1187>
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
    int lo = 0, hi = N - 1;
    Hash<1187> hash(s);
    Hash<29> hash2(s);
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        unordered_set<long long> ck;
        bool found = false;
        for (int i=mid; i < N; i++) {
            int begin = i - mid;
            long long val = hash.value(begin, mid + 1) * 1LL * MOD + hash2.value(begin, mid + 1);
            if (ck.find(val) == ck.end()) {
                ck.insert(val);
            } else {
                found = true;
                break;
            }
        }

        if (found) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo << endl;
    return 0;
}
