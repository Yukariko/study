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
    int T;
    cin >> T;

    while (T--) {
        int S, F;
        cin >> S >> F;

        int xorsum = ((F + 1) / 2 - (S) / 2) % 2;
        for (int i=1; (1 << i) <= F; i += 1) {
            int nth = F % (1 << (i + 1));
            if (nth >= (1 << i) && nth % 2 == 0) {
                xorsum ^= 1 << i;
            }
        }

        S -= 1;
        for (int i=1; (1 << i) <= S; i += 1) {
            int nth = S % (1 << (i + 1));
            if (nth >= (1 << i) && nth % 2 == 0) {
                xorsum ^= 1 << i;
            }
        }

        cout << xorsum << endl;
    }

    return 0;
}
