#include <iostream>
#include <algorithm>

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

    vector<string> a;
    for (int i=0; i < N; i++) {
        string s;
        cin >> s;

        a.emplace_back(s.substr(s.rfind(".") + 1));
    }

    sort(a.begin(), a.end());

    int cnt = 1;
    for (int i=1; i < N; i++) {
        if (a[i-1] != a[i]) {
            cout << a[i-1] << " " << cnt << endl;
            cnt = 1;
        } else {
            cnt++;
        }
    }

    cout << a[N-1] << " " << cnt << endl;

    return 0;
}
