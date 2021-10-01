#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int MOD = 1e9 + 7;

int exp(int n, int m)
{
    if (m == 1) return n;
    if (m & 1) return 1LL * n * exp(n, m - 1) % MOD;
    return exp(1LL * n * n % MOD, m / 2);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;


    auto fact = [&](int n) {
        int res = 1;
        for (int i=2; i <= n; i++)
            res = 1LL * res * i % MOD;
        return res;
    };

    int p = fact(N);
    int q = fact(K);
    int r = fact(N - K);

    int nCm = 1LL * p * exp(q, MOD - 2) % MOD * exp(r, MOD - 2) % MOD;
    cout << nCm << endl;
    return 0;
}
