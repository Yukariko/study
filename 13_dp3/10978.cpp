#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

ll cache[21];

ll solve(int pos)
{
    if (pos == 1) {
        return 0;
    }
    if (pos == 2) {
        return 1;
    }

    ll& ans = cache[pos];
    if (ans != -1) {
        return ans;
    }
    
    return ans = (pos - 1) * (solve(pos - 1) + solve(pos - 2));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;

    memset(cache, -1, sizeof(cache));
    while (T--) {
        int N;
        cin >> N;
        cout << solve(N) << endl;
    }

    return 0;
}
