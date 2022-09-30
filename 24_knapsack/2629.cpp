#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

bool d[31][40000 * 30 + 1];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;

    int sum = 0;

    d[0][0] = true;
    for (int i=1; i <= N; i++) {
        int n;
        cin >> n;
        for (int j=0; j <= sum; j++) {
            if (d[i-1][j]) {
                d[i][j] = true;
                d[i][j + n] = true;
                d[i][abs(j - n)] = true;
            }
        }
        sum += n;
    }

    int M;
    cin >> M;

    while (M--) {
        int n;
        cin >> n;

        if (d[N][n]) {
            cout << "Y ";
        } else {
            cout << "N ";
        }
    }

    cout << "\n" << endl;

	return 0;
}
