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

    const int MAX_N = 50000;
    vector<int> mu(MAX_N + 1);
    mu[1] = 1;
    for (int i=1; i <= MAX_N; i++) {
        for (int j=i * 2; j <= MAX_N; j += i) {
            mu[j] -= mu[i];
        }
    }

    int N;
    cin >> N;
    ll lo = N, hi = 2 * N;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        int cnt = 0;
        for (int i=1; i * i <= mid; i++) {
            int nsq = mid / (i * i);
            cnt += mu[i] * nsq;
        }
        if (cnt >= N) hi = mid - 1;
        else lo = mid + 1;
    }
    cout << lo << endl;

    return 0;
}
