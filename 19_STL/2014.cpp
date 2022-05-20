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
	int K, N;
	cin >> K >> N;

	vector<int> a(K);
	for (int& n : a) {
		cin >> n;
	}

	set<int> ck;
	for (int n : a) {
		ck.insert(n);
	}

	for (int i=1; i < N; i++) {
		for (int n : a) {
			ll next = 1LL * *ck.begin() * n;
			if (ck.size() == N && *ck.rbegin() < next) {
				break;
			} else if (ck.size() == N) {
				ck.erase(--ck.end());
			}
			ck.insert(next);
		}

		ck.erase(ck.begin());
	}

	cout << *ck.begin() << endl;

	return 0;
}
