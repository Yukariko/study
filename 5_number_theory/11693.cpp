#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int MOD = 1e9 + 7;

int exp(int n, ll m)
{
    if (m == 0) return 1;
    if (m == 1) return n;
    if (m & 1) return 1LL * n * exp(n, m - 1) % MOD;
    return exp(1LL * n * n % MOD, m / 2);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    
    vector<pair<int, ll>> factors;
    for (int i=2; i * i <= N; i++) {
        if (N % i == 0) {
            int cnt = 0;
            do { N /= i; cnt++; } while (N % i == 0);
            factors.emplace_back(i, 1LL * cnt * M);
        }
    }
    if (N > 1) factors.emplace_back(N, M);

    int ans = 1;
    for (auto [n, c] : factors) {
        int cnt = (exp(n, c + 1) - 1 + MOD) % MOD;
        cnt = 1LL * cnt * exp(n - 1, MOD - 2) % MOD;
        ans = 1LL * ans * cnt % MOD;
    }

    cout << ans << endl;
    return 0;
}
