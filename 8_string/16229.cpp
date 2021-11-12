#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

vector<int> make_z(const char *s, int n)
{
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i=1; i < n; i++) {
        if (i > r) {
            l = r = i;
            while (l < n && s[r - l] == s[r]) r++;
            z[i] = r - l; r--;
        } else {
            int k = i - l;
            if (z[k] < r - i + 1) z[i] = z[k];
            else {
                l = i;
                while (r < n && s[r - l] == s[r]) r++;
                z[i] = r - l; r--;
            }
        }

    }
    return z;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    
    if (n <= k) {
        cout << n << endl;
        return 0;
    }

    auto z = make_z(s.c_str(), n);
    int ans = 0;
    for (int i=n-1; i > 0; i--) {
        int lenp = i;
        int nump = (n + k) / lenp;
        int roff = lenp * nump - lenp;
        if (z[lenp] == n - lenp && lenp * nump >= n && (roff >= n || z[roff] == n - roff)) {
            ans = lenp;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
