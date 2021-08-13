#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

template<int MOD = static_cast<int>(1e9)+7>
struct matrix
{
	int N, M;
	vector<vector<int>> mat;

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

	int N, M;
	cin >> N >> M;
	matrix a(N, M);

	for (int i=0; i < N; i++) for (int j=0; j < M; j++)
		cin >> a.mat[i][j];
	
	int N2, M2;
	cin >> N2 >> M2;
	matrix b(N2, M2);

	for (int i=0; i < N2; i++) for (int j=0; j < M2; j++)
		cin >> b.mat[i][j];

	matrix ans = a * b;
	ans.print();

    return 0;
}
