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

	int ans = 0;
	for (int i=0; i < N; i++) {
		int n;
		cin >> n;
		ans ^= n;
	}

	cout << ans << endl;
    return 0;
}
