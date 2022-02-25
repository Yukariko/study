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
	int N, D;
	cin >> N >> D;

	vector<int> T(N), V(N);
	for (int& n : T) cin >> n;
	for (int& n : V) cin >> n;

	ll ans = 0;
	for (int i=0; i < N; i++) {
		for (int j=i, e=min(i + D + 1, N); j < e; j++) {
			ll day = j - i;
			ll sum = day * T[j] + V[i];
			ans = max(ans, sum);
		}
	}

	cout << ans << endl;

	return 0;
}
