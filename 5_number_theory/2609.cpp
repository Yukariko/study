#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int gcd(int a, int b)
{
    return b? gcd(b, a % b): a;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M;
    cin >> N >> M;

    cout << gcd(N, M) << endl;
    cout << lcm(N, M) << endl;
    return 0;
}
