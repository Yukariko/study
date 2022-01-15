#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

ll cache[31][31];

ll solve(int w, int h)
{
    if (h < 0) {
        return 0;
    }
    if (w == 0) {
        return 1;
    }

    ll& ret = cache[w][h];
    if (ret != -1) {
        return ret;
    }

    return ret = solve(w - 1, h + 1) + solve(w, h - 1);
}

void init()
{
    for (int i=0; i <= 30; i++) {
        cache[0][i] = 1;
    }
    for (int i=1; i <= 30; i++) {
        cache[i][0] = cache[i-1][1];
        for (int j=1; j <= 29; j++) {
            cache[i][j] = cache[i-1][j+1] + cache[i][j-1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    memset(cache, -1, sizeof(cache));

    init();

    for (int N; cin >> N, N;) {
        cout << solve(N, 0) << endl;
    }


    return 0;
}
