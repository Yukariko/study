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

    int N, K;
    cin >> N >> K;

    vector<int> divs;
    for (int i=1; i * i <= N; i++) {
        if (N % i == 0) {
            divs.push_back(i);
            if (i * i != N) divs.push_back(N / i);
        }
    }

    if (divs.size() < K) {
        cout << 0 << endl;
    } else {
        nth_element(divs.begin(), divs.begin() + K - 1, divs.end());
        cout << divs[K-1] << endl;
    }
    return 0;
}
