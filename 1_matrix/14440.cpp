#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

struct matrix
{
	int mat[2][2] = { { 1, 0 }, { 0, 1 } };

	matrix(){}
	matrix(int x, int y)
	{
		mat[0][0] = x, mat[0][1] = y;
		mat[1][0] = 1,  mat[1][1] = 0;
	}

	matrix operator* (const matrix& m)
	{
		matrix res;

		for (int i=0; i < 2; i++) {
			for (int j=0; j < 2; j++) {
				res.mat[i][j] = 0;
				for (int k=0; k < 2; k++) {
					res.mat[i][j] += mat[i][k] * m.mat[k][j];
					res.mat[i][j] %= 100;
				}
			}
		}

		return res;
	}

	matrix pow(int n)
	{
		matrix res;
		matrix mul = *this;

		while (n) {
			if (n % 2) { res = res * mul; }
			mul = mul * mul;
			n /= 2;
		}
		return res;
	}
};



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int x, y, n;
	string a0, a1;
	cin >> x >> y >> a0 >> a1 >> n;
	if (n == 0) { cout << a0 << endl; return 0; }
	if (n == 1) { cout << a1 << endl; return 0; }

	matrix m(x, y);
	matrix ans = m.pow(n-1);

	int a0n = (a0[0] - '0') * 10 + a0[1] - '0';
	int a1n = (a1[0] - '0') * 10 + a1[1] - '0';

	int an = (ans.mat[0][0] * a1n + ans.mat[0][1] * a0n) % 100;

	cout << an / 10 << an % 10 << endl;
    return 0;
}
