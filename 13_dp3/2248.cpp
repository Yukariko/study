#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

unsigned int N, L, K;
bool used[32][32];
unsigned int cache[32][32];

unsigned int solve(int pos, int bit, int bin)
{
    if (bit < 0) {
        return 0;
    }

    if (pos == N) {
        if (--K == 0) {
            for (int i=0; i < N; i++) {
                cout << !!(bin & (1 << i));
            }
            cout << endl;
            exit(0);
        }
        return 1;
    }

    unsigned int& ans = cache[pos][bit];
    if (used[pos][bit] && ans < K) {
        K -= ans;
        return ans;
    }
    
    used[pos][bit] = true;

    return ans = solve(pos + 1, bit, bin) + solve(pos + 1, bit - 1, bin | (1 << pos));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> L >> K;
    solve(0, L, 0);

    return 0;
}
