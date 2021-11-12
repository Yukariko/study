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
    string a, b;
    getline(cin, a);
    getline(cin, b);

    if (a.length() < b.length()) {
        cout << 0 << endl;
        return 0;
    }

    int len = b.length();
    int ans = 0;
    for (int i=0; i + len <= a.length(); i++) {
        bool full_matched = true;
        for (int j=0; b[j]; j++) {
            if (a[i + j] != b[j]) {
                full_matched = false;
                break;
            }
        }
        if (full_matched) {
            ans++;
            i += len - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
