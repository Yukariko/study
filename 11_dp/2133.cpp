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

    if (N % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> d(N + 1);
    d[2] = 3;
    for (int i=4; i <= N; i+=2) {
        d[i] = 2;
        d[i] += d[i - 2] * 3;
        for (int j=4; j < i; j+=2) {
            d[i] += d[i - j] * 2;
        }
    }
    
    cout << d[N] << endl;

    return 0;
}
