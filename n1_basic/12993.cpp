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

    int N, M;
    cin >> N >> M;

    auto to_base_3 = [](int n) {
        int res = 0;
        int base = 1;
        while (n > 0) {
            if (n % 3 == 2) {
                return -1;
            }
            res += base * (n % 3);
            n /= 3;
            base *= 2;
        }
        return res;
    };

    int a = to_base_3(N), b = to_base_3(M);
    if (a == -1 || b == -1 || ((a + b + 1) & (a + b)) != 0) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }

    return 0;
}
