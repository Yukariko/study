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

    vector<int> a(N);
    for (int& n : a) cin >> n;

    vector<int> f(33);
    f[0] = 1, f[1] = 2;
    for (int i=2; i < f.size(); i++)
        f[i] = f[i-1] + f[i-2];

    vector<int> g(*max_element(a.begin(), a.end()) + 1);

    for (int i=1, e=g.size(); i < e; i++) {
        int actions = 0;
        for (int j=0; f[j] <= i; j++) {
            actions |= 1 << g[i - f[j]];
        }
        actions = ~actions;
        g[i] = 31 - __builtin_clz(actions & -actions);
    }

    int ans = 0;
    for (int n : a) ans ^= g[n];
    cout << (ans? "koosaga": "cubelover") << endl;
    return 0;
}

