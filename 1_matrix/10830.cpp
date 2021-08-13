#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int MOD = 1000;

struct matrix
{
	int N, M;
	vector<vector<int>> mat;

    matrix (int N) : N(N), M(N), mat(N, vector<int>(N))
    {
        for (int i=0; i < N; i++)
            mat[i][i] = 1;
    }
	matrix (int N, int M) : N(N), M(M), mat(N, vector<int>(M)) {}

	matrix operator* (const matrix& m) const
	{
		if (M != m.N) exit(1);
		matrix res(N, m.M);
		for (int i=0; i < N; i++) for (int j=0; j < m.M; j++) {
			for (int k=0; k < M; k++) {
				res.mat[i][j] += mat[i][k] * m.mat[k][j] % MOD;
				res.mat[i][j] %= MOD;
			}
		}
		return res;
	}

	matrix pow(ll n)
	{
		matrix res(N);
		matrix mul = *this;
		while (n) {
			if (n % 2) res = res * mul;
			mul = mul * mul;
			n /= 2;
		}
		return res;
	}

	void print()
	{
		for (int i=0; i < N; i++) {
			for (int j=0; j < M; j++) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	ll M;
	cin >> N >> M;
	matrix a(N, N);
	for (int i=0; i < N; i++) for (int j=0; j < N; j++)
		cin >> a.mat[i][j];
	matrix ans = a.pow(M);
	ans.print();

    return 0;
}

