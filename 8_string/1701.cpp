#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int make_pi(const char *s, int m)
{
    vector<int> pi(m);
    int pos = 1, matched = 0, res = 0;
    while (pos + matched < m) {
        if (s[pos + matched] == s[matched]) {
            matched++;
            res = max(res, matched);
            pi[pos + matched - 1] = matched;
        } else {
            if (matched == 0) pos++;
            else {
                pos += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    cin >> s;

    int ans = 0;
    for (int i=0; i < s.length(); i++) {
        auto pi = make_pi(s.c_str() + i, s.length() - i);
        ans = max(ans, pi);
    }

    cout << ans << endl;

    return 0;
}
