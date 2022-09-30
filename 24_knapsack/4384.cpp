#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

ll d[45001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;

    vector<int> a(N);
    int sum = 0;
    for (int& n : a) {
        cin >> n;
        sum += n;
    }

    d[0] = true;
    for (int i=0; i < N; i++) {
        for (int j=sum - a[i]; j >= 0; j--) {
            d[j + a[i]] |= d[j] << 1;
        }
    }

    ll half = 1LL << (N / 2);
    int minDiff = sum;
    int ans = 0;
    for (int i=0; i <= sum; i++) {
        if (d[i] & half) {
            int diff = abs(sum - i - i);
            if (diff < minDiff) {
                minDiff = diff;
                ans = i;
            }
        }
    }

    cout << min(ans, sum - ans) << " " << max(ans, sum - ans) << endl;
	return 0;
}
