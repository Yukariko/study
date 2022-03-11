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
	vector<string> a(N);
	for (auto& s : a) cin >> s;
	sort(a.begin(), a.end(), [](auto& p, auto& q) {
		return p + q < q + p;
	});

	if (a.back() == "0") {
		cout << 0 << endl;
		return 0;
	}
	for (int i=N-1; i >= 0; i--) {
		cout << a[i];
	}
	cout << endl;

	return 0;
}


