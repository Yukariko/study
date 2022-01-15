#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int MOD = 1e9 + 7;

int N;
int cache[5001][5001];

int solve(int pos, int open)
{
    if (open < 0) {
        return 0;
    }
    if (pos == 0) {
        return !open;
    }

    int& ret = cache[pos][open];
    if (ret != -1) {
        return ret;
    }

    ret = (solve(pos - 1, open + 1) + solve(pos - 1, open - 1)) % MOD;
    return ret;
}

int iterative()
{
    memset(cache, 0, sizeof(cache));
    cache[0][0] = 1;
    for (int i=1; i <= 5000; i++) {
        cache[i][0] = cache[i-1][1];
        cache[i][i] = cache[i-1][i-1];
        for (int j=1; j < i; j++) {
            cache[i][j] = (cache[i-1][j+1] + cache[i-1][j-1]) % MOD;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T;
    cin >> T;

    memset(cache, -1, sizeof(cache));
    iterative();
    while (T--) {
        cin >> N;
        cout << cache[N][0] << endl;
        //cout << solve(N, 0) << endl;
    }

    return 0;
}
