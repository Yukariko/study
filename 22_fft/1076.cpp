#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

using cpx = complex<double>;

void dft(vector<cpx>& a, cpx w)
{
	int n = a.size();
	if (n == 1) return;

	vector<cpx> even(n / 2), odd(n / 2);
	for (int i = 0; i < n; i++) {
		if (i % 2) {
			odd[i / 2] = a[i];
		} else {
			even[i / 2] = a[i];
		}
	}

	dft(even, w * w);
	dft(odd, w * w);

	cpx wn(1, 0);

	for (int i = 0; i < n / 2; i++) {
		a[i] = even[i] + wn * odd[i];
		a[i + n / 2] = even[i] - wn * odd[i];
		wn *= w;
	}
}

vector<cpx> fft(vector<cpx> a, vector<cpx> b)
{
	int n = 1;
	int m = a.size() + b.size() - 1;
	while (n < m) n *= 2;

	a.resize(n);
	b.resize(n);

	vector<cpx> c(n);

	cpx w(cos(2 * M_PI / n), sin(2 * M_PI / n));

	dft(a, w);
	dft(b, w);

	for (int i = 0; i < n; i++) {
		c[i] = a[i] * b[i];
	}

	dft(c, cpx(1, 0) / w);

	for (int i = 0; i < n; i++) {
		c[i] /= cpx(n, 0);
		c[i] = cpx(round(c[i].real()), round(c[i].imag()));
	}

	return c;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N;
	cin >> N;

	vector<cpx> a(N * 2 - 1), b(N);
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		a[N - 1 - i] = cpx(n, 0);
		if (i > 0) a[2 * N - 1 - i] = cpx(n, 0);
	}

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		b[i] = cpx(n, 0);
	}

	auto c = fft(a, b);
	int ans = 0;
	for (auto& n : c) {
		ans = max<int>(ans, n.real());
	}

	cout << ans << endl;

	return 0;
}
