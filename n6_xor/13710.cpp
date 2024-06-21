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

    ll sum = 0;

    vector<int> bitsum(32);
    vector<ll> bitssum(32);
    for (int i=0; i < N; i++) {
        for (int j=0; j < 32; j++) {
            int bit = a[i] & (1 << j);
            if (bit) {
                bitsum[j] += i - 2 * bitsum[j];
                bitsum[j]++;
            }
            bitssum[j] += bitsum[j];
        }
    }

    for (int j=0; j < 32; j++) {
        sum += bitssum[j] * (1LL << j);
    }


    cout << sum << endl;

    return 0;
}
