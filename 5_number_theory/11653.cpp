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

    for (int i=2; i * i <= N; i++) {
        while (N % i == 0) {
            N /= i;
            cout << i << endl;
        }
    }

    if (N > 1) cout << N << endl;
    return 0;
}
