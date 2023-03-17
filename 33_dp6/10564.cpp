#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int INF = 1e9;

int N, M;
int a[11];

int cache[5001][501];

int solve(int sum, int point)
{
    if (sum > N) {
        return -INF;
    }
    if (sum == N) {
        return 0;
    }

    int& ret = cache[sum][point];
    if (ret != -1) {
        return ret;
    }

    ret = -INF;
    for (int i=0; i < M; i++) {
        ret = max(ret, a[i] + solve(sum + point + a[i], point + a[i]));
    }
    return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;

    while (T--) {
        cin >> N >> M;
        for (int i=0; i < M; i++) {
            cin >> a[i];
        }
        sort(a, a + M);
        memset(cache, -1, sizeof(cache));
        int ans = solve(0, 0);
        if (ans < 0) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }

	return 0;
}
