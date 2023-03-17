#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int N, M;
int a[101];

int cache[101][11][2001];

int solve(int pos, int clean, int dirty)
{
    if (pos == N) {
        return 0;
    }

    int& ret = cache[pos][clean][dirty];
    if (ret != -1) {
        return ret;
    }

    ret = dirty * a[pos] + solve(pos + 1, clean, dirty + a[pos]);
    if (clean < M) {
        ret = min(ret, dirty * a[pos] + solve(pos + 1, clean + 1, 0));
    }

    return ret;
}

void construct(int pos, int clean, int dirty)
{
    if (pos == N) {
        return;
    }

    int ret = cache[pos][clean][dirty];
    if (pos < N - 1 && clean < M && ret == dirty * a[pos] + solve(pos + 1, clean + 1, 0)) {
        cout << pos + 1 << " ";

        construct(pos + 1, clean + 1, 0);
        return;
    }

    construct(pos + 1, clean, dirty + a[pos]);
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for (int i=0; i < N; i++) {
        cin >> a[i];
    }

    memset(cache, -1, sizeof(cache));
    cout << solve(0, 0, 0) << endl;
    construct(0, 0, 0);
    cout << endl;
	return 0;
}
