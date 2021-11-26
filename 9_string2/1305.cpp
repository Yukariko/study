#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int BASE = 29;
const int MOD = 1e9 + 7;

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
	cin >> N;

	string s;
	cin >> s;

	Hash hash(s);
	for (int i=1; i <= N; i++) {
		bool matched = true;

		int rem = N - i;
		for (int j=i; j * 2 <= N; j*=2) {
			int l = hash.value(0, j);
			int r = hash.value(j, j);
			if (l != r) {
				matched = false;
				break;
			}
			rem = N - j * 2;
		}

		if (!matched) continue;
		if (rem == 0) {
			cout << i << endl;
			return 0;
		}
		int rp = N - rem;
		int l = hash.value(0, rem);
		int r = hash.value(rp, rem);
		if (l == r) {
			cout << i << endl;
			return 0;
		}
	}

    return 0;
}
