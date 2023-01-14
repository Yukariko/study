#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

volatile int counter;
pthread_mutex_t plock;

void *run(void* arg)
{
	for (int i=0; i < 1000000; i++) {
		pthread_mutex_lock(&plock);
		counter++;
		pthread_mutex_unlock(&plock);
	}
	return NULL;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	pthread_t threads[2];

	pthread_mutex_init(&plock, NULL);
	pthread_create(&threads[0], NULL, run, 0x1);
	pthread_create(&threads[1], NULL, run, 0x2);

	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);

	cout << counter << endl;

	return 0;
}
