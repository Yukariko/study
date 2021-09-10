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

	for (int i=1; i <= N; i++) {
		vector<int> g(32);
		for (int j=30; j >= 0; j--) {
			int& canwin = g[j];
			for (int k=1; k <= i && j + k <= 31; k++) {
				canwin |= !g[j + k];
			}
		}

		if (!g[1]) cout << i << endl;
	}

    return 0;
}

