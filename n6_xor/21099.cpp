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
    for (int& n : a) {
        cin >> n;
    }

    if (N > 512) {
        cout << "Yes" << endl;
        return 0;
    }

    vector<bool> bit(1 << 17);

    for (int i=0; i < N; i++) {
        for (int j=i + 1; j < N; j++) {
            if (bit[a[i] ^ a[j]]) {
                cout << "Yes" << endl;
                return 0;
            }
            bit[a[i] ^ a[j]] = true;
        }
    }

    cout << "No" << endl;
    return 0;
}
