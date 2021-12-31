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
    int N;
    cin >> N;
    vector<int> d(N + 1);
    d[1] = 2;
    d[2] = 3 + 2 * d[1];
    int sum = d[1] + d[2];
    for (int i=3; i <= N; i++) {
        d[i] = (2 + 1LL * sum * 2 + d[i - 2]) % MOD;
        sum = (sum + d[i]) % MOD;
    }

    cout << d[N] << endl;

    return 0;
}
