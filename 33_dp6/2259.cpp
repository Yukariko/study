#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int N, S;
tuple<int, int, int> a[6667];

int cache[6667];

double dist(int ax, int ay, int bx, int by)
{
    return sqrt(1LL * (ax - bx) * (ax - bx) + 1LL * (ay - by) * (ay - by));
}

int solve(int pos)
{
    int& ret = cache[pos];
    if (ret != -1) {
        return ret;
    }

    auto& [ct, cx, cy] = a[pos];

    ret = 0;
    for (int i=pos + 1; i <= N; i++) {
        auto& [nt, nx, ny] = a[i];
        int dt = nt - ct;
        if (sqrt(S * S) * sqrt(1LL * dt * dt) >= dist(cx, cy, nx, ny)) {
            ret = max(ret, 1 + solve(i));
        }
    }

    return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> S;
    for (int i=1; i <= N; i++) {
        auto& [t, x, y] = a[i];
        cin >> x >> y >> t;
    }

    sort(a + 1, a + N + 1);
    memset(cache, -1, sizeof(cache));

    cout << solve(0) << endl;

	return 0;
}
