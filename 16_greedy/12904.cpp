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
    cin >> a >> b;

    while (a.size() < b.size()) {
        if (b.back() == 'A') {
            b.pop_back();
        } else {
            b.pop_back();
            reverse(b.begin(), b.end());
        }
    }

    cout << (a == b? 1 : 0) << endl;

    return 0;
}

