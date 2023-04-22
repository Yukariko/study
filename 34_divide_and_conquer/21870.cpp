#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int N;
int a[200001];

int solve(int l, int r)
{
    if (l == r) {
        return a[l];
    }

    int m = (l + r + 1) / 2;
    int ld = a[l];
    for (int i=l + 1; i < m; i++) {
        ld = gcd(ld, a[i]);
    }

    int rd = a[r];
    for (int i=r - 1; i >= m; i--) {
        rd = gcd(rd, a[i]);
    }

    return max(ld + solve(m, r), rd + solve(l, m - 2));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for (int i=0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve(0, N-1) << endl;

	return 0;
}
