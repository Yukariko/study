#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

vector<vector<int>> sum;
vector<int> d_cur, d_bef;

void compute(int l, int r, int optl, int optr)
{
	if (l > r) return;

	int mid = (l + r) / 2;
	pair<int, int> best = {INT_MAX, -1};

	int s = 0;
	for (int i=mid; i > optr; i--) {
		s += sum[i][mid + 1] - sum[i][i];
	}

	for (int k=optl, e=min(optr, mid); e >= k; e--) {
		s += sum[e][mid + 1] - sum[e][e];
		best = min(best, { (e? d_bef[e-1] : 0) + s, e });
	}

	d_cur[mid] = best.first;
	int opt = best.second;

	compute(l, mid - 1, optl, opt);
	compute(mid + 1, r, opt, optr);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	sum.resize(N, vector<int>(N+1));
	for (int i=0; i < N; i++) {
		cin >> sum[i][1];
		for (int j=1; j < N; j++) {
			int n; cin >> n;
			sum[i][j + 1] = sum[i][j] + n;
		}
	}


	d_cur.resize(N), d_bef.resize(N);
	for (int i=1; i < N; i++) {
		d_bef[i] = d_bef[i-1] + sum[i][i];
	}

	for (int i=1; i < K; i++) {
		compute(0, N-1, 0, N-1);
		swap(d_bef, d_cur);
	}

	cout << d_bef[N-1] << endl;
	return 0;
}
