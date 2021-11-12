#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

vector<int> make_pi(const string& s)
{
    int m = s.length();
    int pos = 1, matched = 0;
    vector<int> pi(m);
    while (pos + matched < m) {
        if (s[pos + matched] == s[matched]) {
            matched++;
            pi[pos + matched - 1] = matched;
        } else if (matched == 0) {
            pos++;
        } else {
            pos += matched - pi[matched - 1];
            matched = pi[matched - 1];
        }
    }
    return pi;
}

bool match(const string& a, const string& b)
{
    auto pi = make_pi(b);
    int n = a.length(), m = b.length();
    int pos = 0, matched = 0;

    while (pos + m <= n) {
        if (matched < m && a[pos + matched] == b[matched]) {
            matched++;
            if (matched == m) {
                return true;
            }
        } else if (matched == 0) {
            pos++;
        } else {
            pos += matched - pi[matched - 1];
            matched = pi[matched - 1];
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    if (match(a, b)) cout << "1" << endl;
    else cout << "0" << endl;

    return 0;
}
