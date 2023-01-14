#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif
using ll = long long;
using ld = long double;

using namespace std;

volatile bool turn;
volatile int counter;
pthread_mutex_t plock;

void *run(void* arg)
{
	bool myturn = arg == nullptr;
	for (int i=0; i < 1000000; i++) {
		atomic_thread_fence(memory_order_release);
		while (turn != myturn);
		counter++;
		atomic_thread_fence(memory_order_acquire);
		turn = !turn;
		for (int j=0; j < 100; j++) {
			volatile int test = 0;
			test++;
		}
	}
	return NULL;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	pthread_t threads[2];

	pthread_mutex_init(&plock, NULL);
	pthread_create(&threads[0], NULL, run, 0x0);
	pthread_create(&threads[1], NULL, run, 0x1);

	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);

	cout << counter << endl;

	return 0;
}
