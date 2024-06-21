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

    ll S, F;
    cin >> S >> F;

    ll xorsum = ((F + 1) / 2 - (S) / 2) % 2;
    for (ll i=1; (1LL << i) <= F; i += 1) {
        ll nth = F % (1LL << (i + 1));
        if (nth >= (1LL << i) && nth % 2 == 0) {
            xorsum ^= 1 << i;
        }
    }

    S -= 1;
    for (ll i=1; (1LL << i) <= S; i += 1) {
        ll nth = S % (1LL << (i + 1));
        if (nth >= (1LL << i) && nth % 2 == 0) {
            xorsum ^= 1LL << i;
        }
    }

    cout << xorsum << endl;

    return 0;
}
