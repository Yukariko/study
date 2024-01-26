#include <iostream>
#include <algorithm>

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

    vector<vector<int>> a(N, vector<int>(N));
    ll sum = 0;
    for (auto& v : a) {
        for (auto& n : v) {
            cin >> n;
            sum += n;
        }
    }

    auto count_of = [&](int h) {
        ll cnt = 0;
        for (auto& v : a) {
            for (auto& n : v) {
                cnt += min(n, h);
            }
        }
        return cnt;
    };

    int lo = 0, hi = 10000000;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (count_of(mid) >= (sum + 1) / 2) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << endl;

    return 0;
}
