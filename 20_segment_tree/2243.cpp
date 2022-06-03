#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

const int MAX_N = 1000000;
int N = MAX_N;
int t[MAX_N * 2];

void update(int pos, int val)
{
	for (t[pos += N] += val; pos > 1; pos /= 2) {
		t[pos / 2] = t[pos] + t[pos ^ 1];
	}
}

int query(int l, int r)
{
	int sum = 0;
	for (l += N, r += N; l < r; l /= 2, r /= 2) {
		if (l & 1) sum += t[l++];
		if (r & 1) sum += t[--r];
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int M;
	cin >> M;

	while (M--) {
		int A, B, C;
		cin >> A;
		if (A == 1) {
			cin >> B;
			int l = 0, r = N-1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (query(0, mid + 1) < B) {
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			cout << l + 1 << endl;
			update(l, -1);
		} else {
			cin >> B >> C;
			update(B - 1, C);
		}
	}

	return 0;
}
