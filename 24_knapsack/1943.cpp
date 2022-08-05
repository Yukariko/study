#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int d[50001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 3;
    while (T--) {
        int N;
        cin >> N;

        vector<pair<int, int>> a(N);
        int sum = 0;
        for (auto& [n, c] : a) {
            cin >> n >> c;
            sum += n * c;
        }

        if (sum % 2) {
            cout << 0 << endl;
            continue;
        }

        sort(a.begin(), a.end());

        memset(d, 0, sizeof(d));
        for (int i=1; i <= a[0].second; i++) {
            int n = i * a[0].first;
            if (n * 2 > sum)
                break;
            d[n] = true;
        }


        for (int i=1; i < N; i++) {
            for (int j=a[i].first; j * 2 <= sum; j++) {
                if (d[j - a[i].first]) {
                    d[j] = true;
                }
            }
        }

        cout << d[sum / 2] << endl;
    }


	return 0;
}
