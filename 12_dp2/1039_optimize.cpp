#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int N, K;
map<int, int> cache[11];

int solve(int pos, int num)
{
    if (pos == 0) {
        return num;
    }

    int& ret = cache[pos][num];
    if (ret != 0) {
        return ret;
    }

    ret = -1;
    char s[8];
    sprintf(s, "%d", num);
    for (int i=1; s[i]; i++) {
        for (int j=0; j < i; j++) {
            if (j == 0 && s[i] == '0') continue;
            swap(s[i], s[j]);
            ret = max(ret, solve(pos - 1, atoi(s)));
            swap(s[i], s[j]);
        }
    }

    return ret;
}

int iterative()
{
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> K;

    //cout << iterative() << endl;

    cout << solve(K, N) << endl;

    return 0;
}

