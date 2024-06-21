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

    vector<int> a(N);
    for (int& n : a) {
        cin >> n;
    }

    vector<int> bitsum(20);
    for (int n : a) {
        for (int i = 0; n > 0; n /= 2, i += 1) {
            bitsum[i] += n & 1;
        }
    }

    ll ans = 0;
    for (int i=0; int n : bitsum) {
        ans += (1LL << i) * (N - n) * n;
        i += 1;
    }

    cout << ans << endl;

    return 0;
}
