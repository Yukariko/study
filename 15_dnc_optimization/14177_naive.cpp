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

	vector<vector<int>> sum(N, vector<int>(N+1));
	for (int i=0; i < N; i++) {
		cin >> sum[i][1];
		for (int j=1; j < N; j++) {
			int n; cin >> n;
			sum[i][j + 1] = sum[i][j] + n;
		}
	}

	vector<int> d_cur(N), d_bef(N);
	for (int i=1; i < N; i++) {
		d_bef[i] = d_bef[i-1] + sum[i][i];
	}

	for (int i=1; i < K; i++) {
		for (int j=0; j < N; j++) {
			d_cur[j] = d_bef[j];
			int s = 0;
			for (int k=j; k >= 0; k--) {
				s += sum[k][j + 1] - sum[k][k];
				d_cur[j] = min(d_cur[j], (k? d_bef[k-1] : 0) + s);
			}
		}
		swap(d_bef, d_cur);
	}

	cout << d_bef[N-1] << endl;
	return 0;
}
