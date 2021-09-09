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

    vector<int> g(N+1);
    for (int i=2; i <= N; i++) {
        vector<bool> actions(i+1);
        for (int j=0; j < i / 2; j++) {
            actions[g[i-j-2] ^ g[j]] = true;
        }
        g[i] = min_element(actions.begin(), actions.end()) - actions.begin();
    }

    cout << (g[N]? 1: 2) << endl;

    return 0;
}
