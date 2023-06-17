#include <iostream>
#include <vector>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;

     while (T--) {
         int N, M, K;
         cin >> N >> M >> K;

         vector<int> a(N);
         int ans = 0;
         int amt = 0;
         for (int i=0; i < N; i++) {
             cin >> a[i];
             amt += a[i];
             if (i >= M) {
                 amt -= a[i - M];
             }
             if (i >= M - 1 && amt < K) {
                 ans++;
             }
         }

         if (N == M) {
             cout << ans << endl;
             continue;
         }

         for (int i=0; i < M - 1; i++) {
             amt -= a[N + i - M];
             amt += a[i];
             if (amt < K) {
                 ans++;
             }
         }

         cout << ans << endl;
     }

	return 0;
}
