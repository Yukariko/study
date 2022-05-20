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
	map<char, int> submit;

	int num_solved = 0;
	int penalty = 0;
	for (int T; cin >> T, T != -1; ) {
		char problem;
		string result;
		cin >> problem >> result;


		if (result == "right") {
			num_solved++;
			penalty += submit[problem] * 20 + T;
		} else {
			submit[problem]++;
		}
	}

	cout << num_solved << " " << penalty << endl;

	return 0;
}
