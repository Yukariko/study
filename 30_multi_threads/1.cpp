#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

volatile int counter;

void *run(void* arg)
{
	for (int i=0; i < 1000000; i++) {
		counter++;
	}
	return NULL;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	pthread_t threads[2];
	pthread_create(&threads[0], NULL, run, 0x1);
	pthread_create(&threads[1], NULL, run, 0x2);

	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);

	cout << counter << endl;

	return 0;
}
