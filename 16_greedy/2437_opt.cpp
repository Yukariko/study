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

	vector<int> a(N);
	for (int& n : a) cin >> n;

	sort(a.begin(), a.end());

	int next = 1;
	for (int i=0; i < N; i++) {
		if (next < a[i]) break;
		next += a[i];
	}

	cout << next << endl;

	return 0;
}
