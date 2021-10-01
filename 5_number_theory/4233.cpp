#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

bool isPrime(int n)
{
    if (n < 2) return false;
    for (int i=2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}

int exp(int n, int m, int mod)
{
    if (m == 1) return n;
    if (m & 1) return 1LL * n * exp(n, m - 1, mod) % mod;
    return exp(1LL * n * n % mod, m / 2, mod);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    for (int p, a; cin >> p >> a, p; ) {
        if (isPrime(p)) cout << "no" << endl;
        else if (exp(a, p, p) == a) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
