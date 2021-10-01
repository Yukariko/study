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

    auto isPrime = [&](int n) {
        if (n < 2) return false;
        //for (int i=2; i < n; i++) if (n % i == 0) return false;
        for (int i=2; i * i <= n; i++) if (n % i == 0) return false;
        return true;
    };

    int ans = 0;
    while (N--) {
        int n;
        cin >> n;
        if (isPrime(n)) ans++;
    }
    cout << ans << endl;

    return 0;
}
