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
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> a(N);
        for (int& n : a)
            cin >> n;

        int M;
        cin >> M;

        vector<int> d(10001);
        d[0] = 1;

        for (int i=0; i < N; i++)
            for (int j=a[i]; j <= M; j++)
                d[j] += d[j-a[i]];

        cout << d[M] << endl;
    }

	return 0;
}
