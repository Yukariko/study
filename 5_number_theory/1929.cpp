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

    vector<bool> sieve(1000001);
    sieve[1] = true;
    for (int i=2; i <= 1000; i++) {
        if (!sieve[i]) {
            for (int j=i * i; j <= 1000000; j += i) {
                sieve[j] = true;
            }
        }
    }

    int M, N;
    cin >> M >> N;

    while (M <= N) {
        if (!sieve[M]) cout << M << endl;
        M++;
    }

    return 0;
}
