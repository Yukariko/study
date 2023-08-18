#include <iostream>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int X;
    cin >> X;

    string s;
    cin >> s;

    int len = s.length();
    int cycle = 1;
    int pos = 2;
    while (pos != len) {
        if (pos <= (len + 1) / 2) {
            pos += pos - 1;
        }
        else {
            int back_pos = len - pos;
            pos = back_pos * 2 + 2;
        }
        cycle++;
    }

    X %= cycle;
    X = cycle - X;
    while (X--) {
        string s2;
        for (int i=0; i < len; i++) {
            if (i % 2 == 0) {
                s2 += s[i / 2];
            } else {
                s2 += s[len - i / 2 - 1];
            }
        }
        s = s2;
    }

    cout << s << endl;

	return 0;
}
