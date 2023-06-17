#include <iostream>
#include <cstring>
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int MOD = 1e9 + 7;
int cache[51][51][51][51];

int solve(int n, int d, int k, int h)
{
    if (d < 0 || k < 0 || h < 0) {
        return 0;
    }
    if (n == 0) {
        return !(d | k | h);
    }

    int& ret = cache[n][d][k][h];
    if (ret != -1) {
        return ret;
    }

    ret = (solve(n - 1, d - 1, k, h) + solve(n  - 1, d, k - 1, h)) % MOD;
    ret = (ret + solve(n - 1, d, k, h - 1)) % MOD;
    ret = (ret + solve(n - 1, d - 1, k - 1, h)) % MOD;
    ret = (ret + solve(n - 1, d - 1, k, h - 1)) % MOD;
    ret = (ret + solve(n - 1, d, k - 1, h - 1)) % MOD;
    ret = (ret + solve(n - 1, d - 1, k - 1, h - 1)) % MOD;
    return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    memset(cache, -1, sizeof(cache));

    int N, D, K, H;
    cin >> N >> D >> K >> H;
    cout << solve(N, D, K, H) << endl;

	return 0;
}
