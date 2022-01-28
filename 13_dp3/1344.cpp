#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int a, b;
double pa, pb;
const bool is_prime[] = {
    false, false, true, true, false,
    true, false, true, false, false,
    false, true, false, true, false,
    false, false, true, false
};

double cache[18][18][18];

double solve(int pos, int acnt, int bcnt)
{
    if (pos == 18) {
        return is_prime[acnt] || is_prime[bcnt]? 1.0: 0.0;
    }

    double& ret = cache[pos][acnt][bcnt];
    if (ret >= 0) {
        return ret;
    }

    ret  = (1.0 - pa) * (1.0 - pb) * solve(pos + 1, acnt, bcnt);
    ret += (1.0 - pa) * pb * solve(pos + 1, acnt, bcnt + 1);
    ret += pa * (1.0 - pb) * solve(pos + 1, acnt + 1, bcnt);
    ret += pa * pb * solve(pos + 1, acnt + 1, bcnt + 1);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> a >> b;
    fill(&cache[0][0][0], &cache[18][0][0], -1.0);
    pa = a / 100.0;
    pb = b / 100.0;

    cout.precision(9);
    cout << fixed << solve(0, 0, 0) << endl;

    return 0;
}
