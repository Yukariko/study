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

	int g[11][11];
	for (int i=0; i < N; i++) {
		for (int j=0; j < N; j++) {
			cin >> g[i][j];
		}
	}

	const int INF = 0x3F3F3F3F;
	int d[1 << 10][11];
	memset(d, 0x3f, sizeof(d));

	d[1 << K][K] = 0;

	for (int i=K; i < (1 << N); i++) {
		if (!(i & (1 << K))) continue;
		for (int j=0; j < N; j++) {
			if (!(i & (1 << j))) continue;
			for (int k=0; k < N; k++) {
				if (!(i & (1 << k))) continue;
				d[i][j] = min(d[i][j], d[i ^ (1 << j)][k] + g[k][j]);
			}
   			for (int k=0; k < N; k++) {
				if (!(i & (1 << k))) continue;
				d[i][k] = min(d[i][k], d[i][j] + g[j][k]);
			}
		}
	}

	int ans = INF;
	for (int i=0; i < N; i++) {
		ans = min(ans, d[(1 << N) - 1][i]);
	}
	cout << ans << endl;
	return 0;
}
