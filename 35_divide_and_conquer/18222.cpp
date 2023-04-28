#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;


int solve(ll k)
{
    if (k <= 1) {
        return k;
    }

    ll sz = 1;
    while (sz * 2 <= k) {
        sz *= 2;
    }

    return !solve(k - sz);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll K;
    cin >> K;


    cout << solve(K - 1) << endl;;

	return 0;
}
