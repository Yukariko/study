#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int N, K;
int cache[11][1000001];

int solve(int pos, int num)
{
    if (pos == 0) {
        return num;
    }

    int& ret = cache[pos][num];
    if (ret != -1) {
        return ret;
    }

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

    memset(cache, -1, sizeof(cache));

    cin >> N >> K;

    //cout << iterative() << endl;

    cout << solve(K, N) << endl;

    return 0;
}
