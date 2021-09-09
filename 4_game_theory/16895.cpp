#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;

    int g = 0;
    vector<int> a(N);
    for (int& n : a) {
        cin >> n;
        g ^= n;
    }

    if (g == 0) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;

#if 0
    for (int n : a) {
        g ^= n;
        for (int i=1; i <= n; i++)
            if ((g ^ (n - i)) == 0)
                ans++;
        g ^= n;
    }
#else
    int msb = 31 - __builtin_clz(g);
    for (int n : a) {
        if (n & (1 << msb)) ans++;
    }
#endif
    cout << ans << endl;
    return 0;
}
