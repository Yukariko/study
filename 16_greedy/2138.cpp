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
	int N;
	cin >> N;

	string a, b, c;
	cin >> a >> b;

	auto toggle = [&](int pos) {
		for (int i=-1; i <= 1; i++) {
			if (0 <= pos + i && pos + i < N) {
				a[pos+i] = a[pos+i] == '0'? '1': '0';
			}
		}
	};

	c = a;

	int ans = 0;
	for (int i = 1; i < N; i++) {
		if (a[i - 1] != b[i - 1]) {
			toggle(i);
			ans++;
		}
	}

	if (a[N-1] == b[N-1]) {
		cout << ans << endl;
		return 0;
	}

	a = c;
	ans = 1;
	toggle(0);
	for (int i = 1; i < N; i++) {
		if (a[i - 1] != b[i - 1]) {
			toggle(i);
			ans++;
		}
	}

	if (a[N-1] == b[N-1]) {
		cout << ans << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}
