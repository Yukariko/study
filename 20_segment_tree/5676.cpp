#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int MAX_N = 100000;

int N;
int t[MAX_N * 2];

void build()
{
	for (int i=N-1; i > 0; i--) {
		t[i] = t[i * 2] * t[i * 2 + 1];
	}
}

void modify(int pos, int val)
{
	for (t[pos += N] = val; pos > 1; pos /= 2) {
		t[pos / 2] = t[pos] * t[pos ^ 1];
	}
}

int query(int l, int r)
{
	int ans = 1;
	for (l += N, r += N; l < r; l /= 2, r /= 2) {
		if (l & 1) ans *= t[l++];
		if (r & 1) ans *= t[--r];
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int K;
	while (cin >> N >> K) {
		for (int i=0; i < N; i++) {
			int n;
			cin >> n;
			t[i + N] = n > 0? 1: n < 0? -1: 0;
		}

		build();

		while (K--) {
			char cmd;
			cin >> cmd;
			if (cmd == 'C') {
				int I, V;
				cin >> I >> V;
				modify(I - 1, V > 0? 1: V < 0? -1: 0);
			} else {
				int L, R;
				cin >> L >> R;

				int res = query(L - 1, R);
				cout << "-0+"[res + 1];
			}
		}
		cout << endl;
	}

	return 0;
}
