#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

bool solve(int pos, int sz, const string& s)
{
    if (sz == 1) {
        return true;
    }

    for (int i=0; i < sz / 2; i++) {
        if (s[pos + i] == s[pos + sz - 1 -i]) {
            return false;
        }
    }

    return solve(pos, sz / 2, s) && solve(pos + 1 + sz / 2, sz / 2, s);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        bool res = solve(0, s.size(), s);
        if (res) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

	return 0;
}
