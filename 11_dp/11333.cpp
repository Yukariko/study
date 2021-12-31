#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> d(10001);
    d[0] = 1;
    d[3] = 3;
    for (int i=6; i < 10000; i+=3) {
        d[i] = 3LL * d[i - 3] % MOD;
        for (int j=6; j <= i; j += 3) {
            int cnt = 2 + (j - 6) / 3;
            d[i] += 2LL * d[i-j] * cnt % MOD;
            d[i] %= MOD;
        }
    }

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        cout << d[N] << endl;
    }

    return 0;
}
