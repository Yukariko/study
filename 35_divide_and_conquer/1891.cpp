#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int D;
string S;

pair<ll, ll> find(int pos)
{
    if (pos == D - 1) {
        switch (S[pos]) {
        case '1': return {1, 1};
        case '2': return {0, 1};
        case '3': return {0, 0};
        case '4': return {1, 0};
        }
        return {-1, -1};
    }

    auto [x, y] = find(pos + 1);
    ll sz = 1LL << (D - pos - 1);
    switch (S[pos]) {
    case '1': return {x + sz, y + sz};
    case '2': return {x, y + sz};
    case '3': return {x, y};
    case '4': return {x + sz, y};
    }

    return {-1, -1};
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll X, Y;
    cin >> D >> S >> X >> Y;

    auto [x, y] = find(0);

    x += X, y += Y;

    if (x < 0 || y < 0 || x >= (1LL << D) || y >= (1LL << D)) {
        cout << -1 << endl;
        return 0;
    }

    for (int i=0; i < D; i++) {
        ll sz = 1LL << (D - i - 1);
        bool xgt = x >= sz;
        bool ygt = y >= sz;
        if (xgt && ygt) {
            cout << 1;
        } else if (xgt) {
            cout << 4;
        } else if (ygt) {
            cout << 2;
        } else {
            cout << 3;
        }
        x %= sz;
        y %= sz;
    }
    cout << endl;
	return 0;
}
