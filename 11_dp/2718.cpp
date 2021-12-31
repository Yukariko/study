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
    vector<int> d(1001);
    d[1] = 1;
    d[2] = 5;
    for (int i=3; i <= 1000; i++) {
        d[i] = (i % 2? 2: 3) + d[i - 1] + d[i - 2] * 4;
        for (int j=3; j < i; j+=2) {
            d[i] += 2 * d[i - j];
        }
        for (int j=4; j < i; j += 2) {
            d[i] += 3 * d[i - j];
        }
    }
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        cout << d[N] << endl;
    }

    return 0;
}
