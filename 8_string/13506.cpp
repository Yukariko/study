#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

vector<int> make_z(const string& s)
{
    int n = s.length();
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

    string s;
    cin >> s;
    auto z = make_z(s);

    int n = s.length();
    int ans = 0;
    int maxeq = 0;
    for (int i=n-1; i > 0; i--) {
        if (z[i] + i == n) {
            ans = maxeq;
            maxeq = z[i];
        } else if (z[i] >= maxeq) {
            ans = maxeq;
        }
    }

    if (ans == 0) {
        cout << -1 << endl;
    } else {
        for (int i=0; i < ans; i++)
            cout << s[i];
        cout << endl;
    }
    return 0;
}
