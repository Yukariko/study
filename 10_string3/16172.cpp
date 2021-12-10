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
    string s, k;
    cin >> s >> k;

    string parsed;
    for (int i=0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            parsed += s[i];
        }
    }

    Hash h_parsed(parsed);
    Hash h_k(k);
    int hash_value = h_k.value(0, k.length());

    for (int i=k.length(); i <= parsed.length(); i++) {
        int begin = i - k.length();
        if (h_parsed.value(begin, k.length()) == hash_value) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}
