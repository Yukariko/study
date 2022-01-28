#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int N;
ll cache[1 << 20];

ll solve(int pos, int mask)
{
    if (mask == (1 << N) - 1) {
        return 1;
    }

    ll& ans = cache[mask];
    if (ans != -1) {
        return ans;
    }

    ans = 0;
    for (int i=0; i < N; i++) {
        if (i != pos && (mask & (1 << i)) == 0) {
            ans += solve(pos + 1, mask | (1 << i));
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;

    while (T--) {
        cin >> N;
        memset(cache, -1, sizeof(cache));
        cout << solve(0, 0) << endl;
    }

    return 0;
}
