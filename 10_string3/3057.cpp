#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int BASE = 7;
const int MOD = 1e9 + 7;

struct Hash
{
	vector<int> h, p;

	Hash(const string & s) : h(s.size()), p(s.size())
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
		if (idx == 0) {
			return h[len - 1];
		}
		return (h[idx + len - 1] - 1LL * h[idx - 1] * p[len] % MOD + MOD) % MOD;
	}
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, M;
	cin >> N >> M;

	vector<Hash> h;
	vector<Hash> rh;
	for (int i=0; i < N; i++) {
		string s;
		cin >> s;
		h.emplace_back(s);
		reverse(s.begin(), s.end());
		rh.emplace_back(s);
	}

	for (int k=min(N, M); k >= 2; k--) {
		for (int i=0; i <= N - k; i++) {
			for (int j=k; j <= M; j++) {
				bool find = true;
				for (int l=0; l <= k / 2; l++) {
					int ol = k - l - 1;
					if (h[i + l].value(j - k, k) != rh[i + ol].value(M - j, k)) {
						find = false;
						break;
					}
				}
				if (find) {
					cout << k << endl;
					return 0;
				}
			}
		}

	}

	cout << -1 << endl;
    return 0;
}
