#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int nCm[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    const int MOD = 10007;

    nCm[0][0] = 1;
    for (int i=1; i <= N; i++) {
        nCm[i][0] = 1;
        for (int j=1; j <= i; j++) {
            nCm[i][j] = (nCm[i - 1][j - 1] + nCm[i - 1][j]) % MOD;
        }
    }

    cout << nCm[N][K] << endl;
    return 0;
}
